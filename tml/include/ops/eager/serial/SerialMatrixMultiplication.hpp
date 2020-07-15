#pragma once

#include "../base/MatmulBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct matmul_backend<Scalar, SEQ>
				{
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("seq");
						const tml::matrix<Scalar> newRight = tml::eager::transpose(right, tml::execution::seq);
						size_t r1 = left.rows(), c1 = left.columns(), r2 = right.rows(), c2 = right.columns();
						for (size_t i = 0; i < r1; i += 32)
							for (size_t j = 0; j < c2; j += 32)
								for (size_t br = 0; br < 32 && i + br < r1; ++br)
									for (size_t bc = 0; bc < 32 && j + bc < c2; ++bc)
										result[j + bc + (i + br)*c2] = TML_TRANSFORM_REDUCE(left.cbegin() + (i + br)*c1, left.cbegin() + (i + br + 1)*c1, newRight.cbegin() + (j + bc)*r2, static_cast<Scalar>(0));
					}
				};
			}
		}
	}
}
