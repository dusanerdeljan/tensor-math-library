#pragma once

#if TML_HAS_CPP17_STL
#include <algorithm>
#include <execution>
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
				struct unary_op_backend<Scalar, STL>
				{
					template<typename OP>
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result, OP&& op)
					{
						TML_LOG_BACKEND("stl");
						std::transform(std::execution::par, matrix.cbegin(), matrix.cend(), result.begin(), op);
					}
				};
			}
		}
	}
}
#endif