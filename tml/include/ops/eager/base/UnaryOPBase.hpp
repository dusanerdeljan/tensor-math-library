#pragma once

#include "..\ExecutionPolicy.hpp"
#include "..\..\..\matrix\Matrix.hpp"

#define TML_STRONG_INLINE static inline

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar, typename Backend>
				struct UnaryOPBackend
				{
					template<typename OP>
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, OP&& op)
					{
						throw std::exception("Selected parallel back-end is not supported.");
					}
				};
			}
		}
	}
}
