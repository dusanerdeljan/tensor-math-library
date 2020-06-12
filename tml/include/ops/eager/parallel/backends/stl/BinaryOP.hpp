#pragma once
#if TML_HAS_CPP17_STL
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
				struct BinaryOPBackend<Scalar, STL>
				{
					template<typename OP>
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
					{
						TML_LOG_BACKEND("stl");
						std::transform(std::execution::par, left.cbegin(), left.cend(), right.cbegin(), result.begin(), op);
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
