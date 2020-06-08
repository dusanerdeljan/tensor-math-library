#pragma once

#include <omp.h>
#include "..\..\..\base\UnaryOPBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct UnaryOPBackend<Scalar, OMP>
				{
					template<typename OP>
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, OP&& op)
					{
						std::cout << "running omp backend" << std::endl;
						omp_set_num_threads(tml::HardawreConcurrency);
						#pragma omp parallel for
						for (int64_t i = 0; i < (int64_t)matrix.Size(); i += 32)
							for (int64_t br = 0; br < 32 && i + br < (int64_t)matrix.Size(); ++br)
								result[i + br] = op(matrix[i + br]);
					}
				};
			}
		}
	}
}