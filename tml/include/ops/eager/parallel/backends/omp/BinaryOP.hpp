#pragma once

#include <omp.h>
#include "UnaryOP.hpp"
#include "..\..\..\ExecutionPolicy.hpp"
#include "..\..\..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace ompbackend
			{
				template<typename Scalar, typename OP>
				void ParallelCustomBinaryOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
				{
					omp_set_num_threads(tml::HardawreConcurrency);
					#pragma omp parallel for
					for (int64_t i = 0; i < (int64_t)left.Size(); i += 32)
						for (int64_t br = 0; br < 32 && i + br < (int64_t)left.Size(); ++br)
							result[i + br] = op(left[i + br], right[i + br]);
				}

				template<typename Scalar, typename OP>
				void ParallelCustomBinaryOP(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result, OP&& op)
				{
					ParallelCustomUnaryOP(left, right, [=](double x) { return op(x, right); });
				}

				template<typename Scalar, typename OP>
				void ParallelCustomBinaryOP(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
				{
					ParallelCustomUnaryOP(left, right, [=](double x) { return op(left, x); });
				}
			}
		}
	}
}
