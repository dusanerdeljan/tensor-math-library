#pragma once

#include <algorithm>
#include "../base/UnaryOPBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct unary_op_backend<Scalar, SEQ>
				{
					template<typename OP>
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result, OP&& op)
					{
						TML_LOG_BACKEND("seq");
						std::transform(matrix.cbegin(), matrix.cend(), result.begin(), op);
					}
				};
			}
		}
	}
}