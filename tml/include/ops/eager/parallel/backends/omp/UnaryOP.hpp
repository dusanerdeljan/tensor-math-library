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
					for (long long i = 0; i < (long long)matrix.Size(); i += 32)
						for (long long br = 0; br < 32 && i + br < (long long)matrix.Size(); ++br)
							result[i+br] = op(matrix[i+br]);
				}
			}
		}
	}
}