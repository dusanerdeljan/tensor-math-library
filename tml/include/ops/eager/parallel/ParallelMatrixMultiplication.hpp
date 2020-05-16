#pragma once

#include <tbb\task.h>
#include "..\ExecutionPolicy.hpp"
#include "ParallelTranspose.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar>
			inline Scalar MultiplyRowColumn(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, size_t row, size_t column, size_t r1, size_t c1, size_t r2, size_t c2)
			{
				Scalar sum = static_cast<Scalar>(0);
				for (size_t i = 0; i < c1; ++i)
					sum += left[row*c1 + i] * right[i + r2*column];
				return sum;
			}

			template<typename Scalar>
			class MatmulTask : public tbb::task
			{
			private:
				tml::Matrix<Scalar>& m_Result;
				const tml::Matrix<Scalar>& m_Left;
				const tml::Matrix<Scalar>& m_Right;
				size_t m_RowBegin;
				size_t m_ColumnBegin;
				size_t m_RowEnd;
				size_t m_ColumnEnd;
				size_t m_R1;
				size_t m_C1;
				size_t m_R2;
				size_t m_C2;
			public:
				MatmulTask(tml::Matrix<Scalar>& result, const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, size_t rowBegin, size_t columnBegin, size_t rowEnd, size_t columnEnd)
					: m_Result(result), m_Left(left), m_Right(right), 
					m_RowBegin(rowBegin), m_ColumnBegin(columnBegin), m_RowEnd(rowEnd), m_ColumnEnd(columnEnd),
					m_R1(left.Rows()), m_C1(left.Columns()), m_R2(right.Columns()), m_C2(right.Rows())
				{
				}
				tbb::task* execute()
				{
					for (size_t i = m_RowBegin; i < m_RowEnd; ++i)
						for (size_t j = m_ColumnBegin; j < m_ColumnEnd; ++j)
							m_Result[i*m_C2 + j] = MultiplyRowColumn(m_Left, m_Right, i, j, m_R1, m_C1, m_R2, m_C2);
					return NULL;
				}
			};

			template<typename Scalar>
			class SingleRowTask : public tbb::task
			{
			private:
				tml::Matrix<Scalar>& m_Result;
				const tml::Matrix<Scalar>& m_Left;
				const tml::Matrix<Scalar>& m_Right;
				size_t m_Row;
				size_t m_R1;
				size_t m_C1;
				size_t m_R2;
				size_t m_C2;
			public:
				SingleRowTask(tml::Matrix<Scalar>& result, const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, size_t row)
					: m_Result(result), m_Left(left), m_Right(right), m_Row(row),
					m_R1(left.Rows()), m_C1(left.Columns()), m_R2(right.Columns()), m_C2(right.Rows())
				{
				}
				tbb::task* execute()
				{
					for (size_t j = 0; j < m_C2; ++j)
						m_Result[m_Row*m_C2 + j] = MultiplyRowColumn(m_Left, m_Right, m_Row, j, m_R1, m_C1, m_R2, m_C2);
					return NULL;
				}
			};

			template<typename Scalar>
			void ParallelMatmulOneOverCores(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
			{
				size_t rows = result.Rows(), cols = result.Columns();
				size_t size = result.Size();
				size_t numCores = tml::HardawreConcurrency;
				if (size <= numCores)
				{
					tbb::task::spawn_root_and_wait(*(new(tbb::task::allocate_root()) MatmulTask<Scalar>(result, left, right, 0, 0, rows, cols)));
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
								tasks.push_back(*(new(tbb::task::allocate_root()) MatmulTask<Scalar>(result, left, right, i, 0, i + stepSize, cols)));
						}
						else
						{
							size_t treshold = numCores - (rows % numCores);
							size_t value = rows / numCores;
							size_t beginIndex = 0;
							for (size_t i = 0; i < numCores; ++i)
							{
								size_t segmentLength = value + (i >= treshold);
								tasks.push_back(*(new(tbb::task::allocate_root()) MatmulTask<Scalar>(result, left, right, beginIndex, 0, beginIndex + segmentLength, cols)));
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
								tasks.push_back(*(new(tbb::task::allocate_root()) MatmulTask<Scalar>(result, left, right, 0, i, rows, i + stepSize)));
						}
						else
						{
							size_t treshold = numCores - (cols % numCores);
							size_t value = cols / numCores;
							size_t beginIndex = 0;
							for (size_t i = 0; i < numCores; ++i)
							{
								size_t segmentLength = value + (i >= treshold);
								tasks.push_back(*(new(tbb::task::allocate_root()) MatmulTask<Scalar>(result, left, right, 0, beginIndex, rows, beginIndex + segmentLength)));
								beginIndex += segmentLength;
							}
						}
						tbb::task::spawn_root_and_wait(tasks);
					}
				}
			}

			template<typename Scalar>
			void ParallelMatmulSingleRow(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
			{
				tbb::task_list tasks;
				for (size_t i = 0; i < left.Rows(); ++i)
					tasks.push_back(*(new(tbb::task::allocate_root()) SingleRowTask<Scalar>(result, left, right, i)));
				tbb::task::spawn_root_and_wait(tasks);
			}

			template<typename Scalar>
			void ParallelMatmul(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				const tml::Matrix<Scalar> newRight = tml::eager::Transpose(right, tml::PARALLEL);
				if (parallelism == tml::ONE_OVER_CORES)
					ParallelMatmulOneOverCores(left, newRight, result);
				else
					ParallelMatmulSingleRow(left, newRight, result);
			}
		}
	}
}