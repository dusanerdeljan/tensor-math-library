#pragma once

#if TML_HAS_TBB
#include <tbb/task.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#include "UnaryOP.hpp"
#include "../../../base/BinaryOPBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct binary_op_backend<Scalar, TBB>
				{
					template<typename LeftIter, typename RightIter, typename ResultIter, typename OP>
					class BinaryTask : public tbb::task
					{
					private:
						LeftIter m_Left;
						LeftIter m_End;
						RightIter m_Right;
						ResultIter m_Result;
						OP m_Op;
					public:
						BinaryTask(const LeftIter& leftBegin, const LeftIter& leftEnd, const RightIter& rightBegin, const ResultIter& result, OP&& op)
							: m_Left(leftBegin), m_End(leftEnd), m_Right(rightBegin), m_Result(result), m_Op(std::move(op))
						{
						}
						tbb::task* execute()
						{
							std::transform(m_Left, m_End, m_Right, m_Result, m_Op);
							return NULL;
						}
					};

					template<typename OP>
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right, tml::matrix<Scalar>& result, OP&& op)
					{
						TML_LOG_BACKEND("tbb");
						size_t size = left.size();
						typedef BinaryTask<typename tml::matrix<Scalar>::const_iterator, typename tml::matrix<Scalar>::const_iterator, typename tml::matrix<Scalar>::iterator, OP> TaskType;
						if (size <= tml::hardware_concurrency)
						{
							tbb::task::spawn_root_and_wait(*(new (tbb::task::allocate_root()) TaskType(left.cbegin(), left.cend(), right.cbegin(), result.begin(), std::move(op))));
						}
						else if (size % tml::hardware_concurrency == 0)
						{
							tbb::task_list tasks;
							size_t stepSize = size / tml::hardware_concurrency;
							for (size_t i = 0; i < size; i += stepSize)
								tasks.push_back(*(new(tbb::task::allocate_root()) TaskType(left.cbegin() + i, left.cbegin() + i + stepSize, right.cbegin() + i, result.begin() + i, std::move(op))));
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
								tasks.push_back(*(new(tbb::task::allocate_root()) TaskType(left.cbegin() + beginIndex, left.cbegin() + beginIndex + segmentLength, right.cbegin() + beginIndex, result.begin() + beginIndex, std::move(op))));
								beginIndex += segmentLength;
							}
							tbb::task::spawn_root_and_wait(tasks);
						}
					}

					template<typename OP>
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& left, Scalar right, tml::matrix<Scalar>& result, OP&& op)
					{
						unary_op_backend<Scalar, TBB>::do_op(left, result, [=](Scalar x) { return op(x, right); });
					}

					template<typename OP>
					TML_STRONG_INLINE void do_op(Scalar left, const tml::matrix<Scalar>& right, tml::matrix<Scalar>& result, OP&& op)
					{
						unary_op_backend<Scalar, TBB>::do_op(right, result, [=](Scalar x) { return op(left, x); });
					}
				};
			}
		}
	}
}
#endif