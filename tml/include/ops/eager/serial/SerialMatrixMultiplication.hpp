#pragma once

#include "..\..\lazy\Expr.hpp"
#include "SerialTranspose.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar>
			void SerialMatmul(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
			{
				const tml::Matrix<Scalar> newRight = tml::eager::Transpose(right, tml::SERIAL);
				size_t r1 = left.Rows(), c1 = left.Columns(), r2 = right.Rows(), c2 = right.Columns();
				for (size_t i = 0; i < r1; ++i)
					for (size_t j = 0; j < c2; ++j)
						for (size_t k = 0; k < r2; ++k)
							result[j + i*c2] += left[i*c1 + k] * newRight[k + r2*j];
			}
		}
	}
}
