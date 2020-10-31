#pragma once

#include <algorithm>
#include "SerialUnaryOP.hpp"
#include "../base/BinaryOPBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct binary_op_backend<Scalar, SEQ>
				{
					template<typename OP>
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right, tml::matrix<Scalar>& result, OP&& op)
					{
						TML_LOG_BACKEND("seq");
						std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), op);
					}

					template<typename OP>
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& left, Scalar right, tml::matrix<Scalar>& result, OP&& op)
					{
						unary_op_backend<Scalar, SEQ>::do_op(left, result, [=](Scalar x) { return op(x, right); });
					}

					template<typename OP>
					TML_STRONG_INLINE void do_op(Scalar left, const tml::matrix<Scalar>& right, tml::matrix<Scalar>& result, OP&& op)
					{
						unary_op_backend<Scalar, SEQ>::do_op(right, result, [=](Scalar x) { return op(left, x); });
					}
				};
			}
		}
	}
}
