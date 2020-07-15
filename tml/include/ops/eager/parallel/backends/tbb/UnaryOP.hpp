#pragma once

#if TML_HAS_TBB
#include <tbb/task.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include "../../../base/UnaryOPBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct unary_op_backend<Scalar, TBB>
				{
					template<typename ReadIter, typename WriteIter, typename OP>
					class UnaryTask : public tbb::task
					{
					private:
						ReadIter m_Begin;
						ReadIter m_End;
						WriteIter m_Result;
						OP m_Op;
					public:
						UnaryTask(const ReadIter& begin, const ReadIter& end, const WriteIter& result, OP&& op) : m_Begin(begin), m_End(end), m_Result(result), m_Op(std::move(op)) {}
						tbb::task* execute()
						{
							std::transform(m_Begin, m_End, m_Result, m_Op);
							return NULL;
						}
					};

					template<typename OP>
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result, OP&& op)
					{
						TML_LOG_BACKEND("tbb");
						size_t size = matrix.size();
						typedef UnaryTask<typename tml::matrix<Scalar>::const_iterator, typename tml::matrix<Scalar>::iterator, OP> TaskType;
						if (size <= tml::hardware_concurrency)
						{
							tbb::task::spawn_root_and_wait(*(new (tbb::task::allocate_root()) TaskType(matrix.cbegin(), matrix.cend(), result.begin(), std::move(op))));
						}
						else if (size % tml::hardware_concurrency == 0)
						{
							tbb::task_list tasks;
							size_t stepSize = size / tml::hardware_concurrency;
							for (size_t i = 0; i < size; i += stepSize)
								tasks.push_back(*(new(tbb::task::allocate_root()) TaskType(matrix.cbegin() + i, matrix.cbegin() + i + stepSize, result.begin() + i, std::move(op))));
							tbb::task::spawn_root_and_wait(tasks);
						}
						else
						{
							size_t treshold = tml::hardware_concurrency - (size % tml::hardware_concurrency);
							size_t value = size / tml::hardware_concurrency;
							tbb::task_list tasks;
							size_t beginIndex = 0;
							for (size_t i = 0; i < tml::hardware_concurrency; ++i)
							{
								size_t segmentLength = value + (i >= treshold);
								tasks.push_back(*(new(tbb::task::allocate_root()) TaskType(matrix.cbegin() + beginIndex, matrix.cbegin() + beginIndex + segmentLength, result.begin() + beginIndex, std::move(op))));
								beginIndex += segmentLength;
							}
							tbb::task::spawn_root_and_wait(tasks);
						}
					}
				};
			}
		}
	}
}
#endif
