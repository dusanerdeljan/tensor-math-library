#pragma once
#if TML_HAS_OMP
#include <omp.h>
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
				struct BinaryOPBackend<Scalar, OMP>
				{
					template<typename OP>
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
					{
						std::cout << "running omp backend" << std::endl;
						omp_set_num_threads(tml::HardawreConcurrency);
						#pragma omp parallel for
						for (int64_t i = 0; i < (int64_t)left.Size(); i += 32)
							for (int64_t br = 0; br < 32 && i + br < (int64_t)left.Size(); ++br)
								result[i + br] = op(left[i + br], right[i + br]);
					}

					template<typename OP>
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result, OP&& op)
					{
						UnaryOPBackend<Scalar, OMP>::DoOP(left, right, [=](double x) { return op(x, right); });
					}

					template<typename OP>
					TML_STRONG_INLINE void DoOP(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
					{
						UnaryOPBackend<Scalar, OMP>::DoOP(left, right, [=](double x) { return op(left, x); });
					}
				};
			}
		}
	}
}
#endif
