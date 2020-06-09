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
				struct BinaryOPBackend<Scalar, SEQ>
				{
					template<typename OP>
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
					{
						std::cout << "running seq backend" << std::endl;
						std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), op);
					}

					template<typename OP>
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result, OP&& op)
					{
						UnaryOPBackend<Scalar, SEQ>::DoOP(left, result, [=](Scalar x) { return op(x, right); });
					}

					template<typename OP>
					TML_STRONG_INLINE void DoOP(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
					{
						UnaryOPBackend<Scalar, SEQ>::DoOP(right, result, [=](Scalar x) { return op(left, x); });
					}
				};
			}
		}
	}
}
