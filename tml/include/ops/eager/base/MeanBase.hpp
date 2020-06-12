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
				struct MeanBackend
				{
					TML_STRONG_INLINE void Mean(const tml::Matrix<Scalar>& matrix, Scalar& result)
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
