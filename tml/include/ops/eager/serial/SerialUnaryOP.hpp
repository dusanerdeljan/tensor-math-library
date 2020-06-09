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
				struct UnaryOPBackend<Scalar, SEQ>
				{
					template<typename OP>
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, OP&& op)
					{
						std::cout << "running seq backend" << std::endl;
						std::transform(matrix.cbegin(), matrix.cend(), result.begin(), op);
					}
				};
			}
		}
	}
}