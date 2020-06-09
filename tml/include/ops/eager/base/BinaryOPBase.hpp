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
				struct BinaryOPBackend
				{
					template<typename OP>
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}

					template<typename OP>
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result, OP&& op)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}

					template<typename OP>
					TML_STRONG_INLINE void DoOP(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
					{
						TML_UNSUPPORTED_BACKEND(Backend);
					}
				};
			}
		}
	}
}