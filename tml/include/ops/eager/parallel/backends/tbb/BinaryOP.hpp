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
				struct BinaryOPBackend<Scalar, TBB>
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
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
					{
						std::cout << "running tbb backend" << std::endl;
						size_t size = left.Size();
						typedef BinaryTask<typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::iterator, OP> TaskType;
						if (size <= tml::HardawreConcurrency)
						{
							tbb::task::spawn_root_and_wait(*(new (tbb::task::allocate_root()) TaskType(left.cbegin(), left.cend(), right.cbegin(), result.begin(), std::move(op))));
						}
						else if (size % tml::HardawreConcurrency == 0)
						{
							tbb::task_list tasks;
							size_t stepSize = size / tml::HardawreConcurrency;
							for (size_t i = 0; i < size; i += stepSize)
								tasks.push_back(*(new(tbb::task::allocate_root()) TaskType(left.cbegin() + i, left.cbegin() + i + stepSize, right.cbegin() + i, result.begin() + i, std::move(op))));
							tbb::task::spawn_root_and_wait(tasks);
						}
						else
						{
							size_t treshold = tml::HardawreConcurrency - (size % tml::HardawreConcurrency);
							size_t value = size / tml::HardawreConcurrency;
							tbb::task_list tasks;
							size_t beginIndex = 0;
							for (size_t i = 0; i < tml::HardawreConcurrency; ++i)
							{
								size_t segmentLength = value + (i >= treshold);
								tasks.push_back(*(new(tbb::task::allocate_root()) TaskType(left.cbegin() + beginIndex, left.cbegin() + beginIndex + segmentLength, right.cbegin() + beginIndex, result.begin() + beginIndex, std::move(op))));
								beginIndex += segmentLength;
							}
							tbb::task::spawn_root_and_wait(tasks);
						}
					}

					template<typename OP>
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result, OP&& op)
					{
						UnaryOPBackend<Scalar, TBB>::DoOP(left, result, [=](Scalar x) { return op(x, right) });
					}

					template<typename OP>
					TML_STRONG_INLINE void DoOP(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
					{
						UnaryOPBackend<Scalar, TBB>::DoOP(right, result, [=](Scalar x) { return op(left, x) });
					}
				};
			}
		}
	}
}
#endif