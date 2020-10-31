#pragma once

#if TML_HAS_TBB
#include <tbb/task.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include "../../../base/MatmulBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct matmul_backend<Scalar, TBB>
				{
					TML_STRONG_INLINE Scalar MultiplyRowColumn(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right, size_t row, size_t column, size_t r1, size_t c1, size_t r2, size_t c2)
					{
						return TML_TRANSFORM_REDUCE(left.cbegin() + row*c1, left.cbegin() + (row + 1)*c1, right.cbegin() + r2*column, static_cast<Scalar>(0));
					}

					class MatmulTask : public tbb::task
					{
					private:
						tml::matrix<Scalar>& m_Result;
						const tml::matrix<Scalar>& m_Left;
						const tml::matrix<Scalar>& m_Right;
						size_t m_RowBegin;
						size_t m_ColumnBegin;
						size_t m_RowEnd;
						size_t m_ColumnEnd;
						size_t m_R1;
						size_t m_C1;
						size_t m_R2;
						size_t m_C2;
					public:
						MatmulTask(tml::matrix<Scalar>& result, const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right, size_t rowBegin, size_t columnBegin, size_t rowEnd, size_t columnEnd)
							: m_Result(result), m_Left(left), m_Right(right),
							m_RowBegin(rowBegin), m_ColumnBegin(columnBegin), m_RowEnd(rowEnd), m_ColumnEnd(columnEnd),
							m_R1(left.rows()), m_C1(left.columns()), m_R2(right.columns()), m_C2(right.rows())
						{
						}
						tbb::task* execute()
						{
							for (size_t i = m_RowBegin; i < m_RowEnd; i += 32)
								for (size_t j = m_ColumnBegin; j < m_ColumnEnd; j += 32)
									for (size_t br = 0; br < 32 && i + br < m_RowEnd; ++br)
										for (size_t bc = 0; bc < 32 && j + bc < m_ColumnEnd; ++bc)
											m_Result[(i + br)*m_C2 + j + bc] = MultiplyRowColumn(m_Left, m_Right, i + br, j + bc, m_R1, m_C1, m_R2, m_C2);
							return NULL;
						}
					};

					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("tbb");
						size_t rows = result.rows(), cols = result.columns();
						const tml::matrix<Scalar> newRight = tml::eager::transpose(right, tml::execution::tbb);
						size_t size = result.size();
						size_t numCores = tml::hardware_concurrency;
						if (size <= numCores)
						{
							tbb::task::spawn_root_and_wait(*(new(tbb::task::allocate_root()) MatmulTask(result, left, newRight, 0, 0, rows, cols)));
						}
						else
						{
							tbb::task_list tasks;
							if (rows >= cols)
							{
								if (rows % numCores == 0)
								{
									size_t stepSize = rows / numCores;
									for (size_t i = 0; i < rows; i += stepSize)
										tasks.push_back(*(new(tbb::task::allocate_root()) MatmulTask(result, left, newRight, i, 0, i + stepSize, cols)));
								}
								else
								{
									size_t treshold = numCores - (rows % numCores);
									size_t value = rows / numCores;
									size_t beginIndex = 0;
									for (size_t i = 0; i < numCores; ++i)
									{
										size_t segmentLength = value + (i >= treshold);
										tasks.push_back(*(new(tbb::task::allocate_root()) MatmulTask(result, left, newRight, beginIndex, 0, beginIndex + segmentLength, cols)));
										beginIndex += segmentLength;
									}
								}
								tbb::task::spawn_root_and_wait(tasks);
							}
							else
							{
								if (cols % numCores == 0)
								{
									size_t stepSize = cols / numCores;
									for (size_t i = 0; i < cols; i += stepSize)
										tasks.push_back(*(new(tbb::task::allocate_root()) MatmulTask(result, left, newRight, 0, i, rows, i + stepSize)));
								}
								else
								{
									size_t treshold = numCores - (cols % numCores);
									size_t value = cols / numCores;
									size_t beginIndex = 0;
									for (size_t i = 0; i < numCores; ++i)
									{
										size_t segmentLength = value + (i >= treshold);
										tasks.push_back(*(new(tbb::task::allocate_root()) MatmulTask(result, left, newRight, 0, beginIndex, rows, beginIndex + segmentLength)));
										beginIndex += segmentLength;
									}
								}
								tbb::task::spawn_root_and_wait(tasks);
							}
						}
					}
				};
			}
		}
	}
}
#endif