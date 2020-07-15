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
				struct binary_op_backend<Scalar, OMP>
				{
					template<typename OP>
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right, tml::matrix<Scalar>& result, OP&& op)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						#pragma omp parallel for
						for (int64_t i = 0; i < (int64_t)left.size(); i += 32)
							for (int64_t br = 0; br < 32 && i + br < (int64_t)left.size(); ++br)
								result[i + br] = op(left[i + br], right[i + br]);
					}

					template<typename OP>
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& left, Scalar right, tml::matrix<Scalar>& result, OP&& op)
					{
						unary_op_backend<Scalar, OMP>::do_op(left, right, [=](double x) { return op(x, right); });
					}

					template<typename OP>
					TML_STRONG_INLINE void do_op(Scalar left, const tml::matrix<Scalar>& right, tml::matrix<Scalar>& result, OP&& op)
					{
						unary_op_backend<Scalar, OMP>::do_op(left, right, [=](double x) { return op(left, x); });
					}
				};
			}
		}
	}
}
#endif
