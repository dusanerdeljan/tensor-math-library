#pragma once

#include "Base.hpp"
#include <numeric>

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar, typename Backend>
				struct MatmulBackend
				{
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
					{
						throw std::exception("Selected backend is not supported.");
					}
				};
			}
		}
	}
}