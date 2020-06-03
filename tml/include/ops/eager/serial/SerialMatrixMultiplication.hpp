#pragma once

#include "SerialTranspose.hpp"
#include <numeric>

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
				for (size_t i = 0; i < r1; i += 32)
					for (size_t j = 0; j < c2; j += 32)
						for (size_t br = 0; br < 32 && i + br < r1; ++br)
							for (size_t bc = 0; bc < 32 && j + bc < c2; ++bc)
								result[j + bc + (i + br)*c2] = std::inner_product(left.cbegin() + (i + br)*r1, left.cbegin() + (i + br + 1)*r1, newRight.cbegin() + (j + bc)*c2, static_cast<Scalar>(0));
			}
		}
	}
}
