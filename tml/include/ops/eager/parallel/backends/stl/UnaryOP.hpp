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
				struct UnaryOPBackend<Scalar, STL>
				{
					template<typename OP>
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, OP&& op)
					{
						std::cout << "running c++17 stl backend" << std::endl;
						std::transform(std::execution::par, matrix.cbegin(), matrix.cend(), result.begin(), op);
					}
				};
			}
		}
	}
}
#endif