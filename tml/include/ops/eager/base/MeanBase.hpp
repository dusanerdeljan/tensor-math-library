#pragma once

#include <numeric>
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
				struct mean_backend
				{
					TML_STRONG_INLINE void mean(const tml::matrix<Scalar>& matrix, Scalar& result)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}

					TML_STRONG_INLINE void rows(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}

					TML_STRONG_INLINE void columns(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}
				};
			}
		}
	}
}
