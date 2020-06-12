#pragma once

#include <numeric>
#include <limits>
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
				struct MaxBackend
				{
					TML_STRONG_INLINE void Max(const tml::Matrix<Scalar>& matrix, Scalar& result)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}

					TML_STRONG_INLINE void Rows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}

					TML_STRONG_INLINE void Columns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}
				};
			}
		}
	}
}
