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
				struct transpose_backend
				{
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}
				};
			}
		}
	}
}