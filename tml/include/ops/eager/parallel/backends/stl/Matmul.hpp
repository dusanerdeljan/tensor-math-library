#pragma once

#if TML_HAS_CPP17_STL
#include <execution>
#include <algorithm>
#include "../../../base/MatmulBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct MatmulBackend<Scalar, STL>
				{
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						const tml::Matrix<Scalar> newRight = tml::eager::Transpose(right, tml::execution::stl);
						size_t r1 = left.Rows(), c1 = left.Columns(), r2 = right.Rows(), c2 = right.Columns();
						// TODO: Implement loop tiling
						const Counter rowCounter(0, r1);
						const Counter columnCounter(0, c2);
						std::for_each(std::execution::par, rowCounter.begin(), rowCounter.end(), [&](int i) {
							std::for_each(std::execution::seq, columnCounter.begin(), columnCounter.end(), [&](int j) {
								result[j + i * c2] = std::transform_reduce(std::execution::seq, left.cbegin() + i * c1, left.cbegin() + (i + 1) * c1, newRight.cbegin() + j * r2, static_cast<Scalar>(0));
							});
						});
					}
				};
			}
		}
	}
}
#endif