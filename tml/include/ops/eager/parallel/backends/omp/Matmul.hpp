#pragma once

#if TML_HAS_OMP
#include <omp.h>
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
				struct MatmulBackend<Scalar, OMP>
				{
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
					{
						std::cout << "running omp backend" << std::endl;
						omp_set_num_threads(tml::HardawreConcurrency);
						const tml::Matrix<Scalar> newRight = tml::eager::Transpose(right, tml::execution::omp);
						int64_t r1 = left.Rows(), c1 = left.Columns(), r2 = right.Rows(), c2 = right.Columns();
						#pragma omp parallel for
						for (int64_t i = 0; i < r1; i += 32)
						{
							#pragma omp parallel for
							for (int64_t j = 0; j < c2; j += 32)
								for (int64_t br = 0; br < 32 && i + br < r1; ++br)
									for (int64_t bc = 0; bc < 32 && j + bc < c2; ++bc)
										result[j + bc + (i + br)*c2] = std::inner_product(left.cbegin() + (i + br)*c1, left.cbegin() + (i + br + 1)*c1, newRight.cbegin() + (j + bc)*r2, static_cast<Scalar>(0));
						}
					}
				};
			}
		}
	}
}
#endif