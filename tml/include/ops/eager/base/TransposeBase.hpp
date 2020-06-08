#pragma once

#include "Base.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar, typename Backend>
				struct TransposeBackend
				{
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						throw std::exception("Selected backend is not supported.");
					}
				};
			}
		}
	}
}