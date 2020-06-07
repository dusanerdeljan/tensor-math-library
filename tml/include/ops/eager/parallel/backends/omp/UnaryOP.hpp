#pragma once

#include <omp.h>
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
				void ParallelCustomUnaryOP(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, OP&& op)
				{
					omp_set_num_threads(tml::HardawreConcurrency);
					#pragma omp parallel for
					for (int64_t i = 0; i < (int64_t)matrix.Size(); i += 32)
						for (int64_t br = 0; br < 32 && i + br < (int64_t)matrix.Size(); ++br)
							result[i+br] = op(matrix[i+br]);
				}
			}
		}
	}
}