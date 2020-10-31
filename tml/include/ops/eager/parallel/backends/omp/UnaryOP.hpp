#pragma once

#if TML_HAS_OMP
#include <omp.h>
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
				struct unary_op_backend<Scalar, OMP>
				{
					template<typename OP>
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result, OP&& op)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						#pragma omp parallel for
						for (int64_t i = 0; i < (int64_t)matrix.size(); i += 32)
							for (int64_t br = 0; br < 32 && i + br < (int64_t)matrix.size(); ++br)
								result[i + br] = op(matrix[i + br]);
					}
				};
			}
		}
	}
}
#endif