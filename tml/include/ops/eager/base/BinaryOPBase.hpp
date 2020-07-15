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
				struct binary_op_backend
				{
					template<typename OP>
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right, tml::matrix<Scalar>& result, OP&& op)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}

					template<typename OP>
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& left, Scalar right, tml::matrix<Scalar>& result, OP&& op)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}

					template<typename OP>
					TML_STRONG_INLINE void do_op(Scalar left, const tml::matrix<Scalar>& right, tml::matrix<Scalar>& result, OP&& op)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}
				};
			}
		}
	}
}
