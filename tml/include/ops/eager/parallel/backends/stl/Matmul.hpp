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
						// TODO: Calculate tile size like L1_CACHE_LINE_SIZE_BYTES / sizeof(Scalar)
						const int rowTiles = 1 + ((r1-1)/32);
						const int colTiles = 1 + ((c2-1)/32);
						const Counter rowCounter(0, rowTiles);
						const Counter columnCounter(0, colTiles);
						std::for_each(std::execution::par, rowCounter.begin(), rowCounter.end(), [&](int i) {
							std::for_each(std::execution::par, columnCounter.begin(), columnCounter.end(), [&](int j) {
								for (size_t br = 0; br < 32 && i*32 + br < r1; ++br)
									for (size_t bc = 0; bc < 32 && j*32 + bc < c2; ++bc)
										result[j*32 + bc + (i*32 + br) * c2] = std::transform_reduce(std::execution::seq, left.cbegin() + (i*32 + br) * c1, left.cbegin() + (i*32 + br + 1) * c1, newRight.cbegin() + (j*32 + bc) * r2, static_cast<Scalar>(0));
							});
						});
					}
				};
			}
		}
	}
}
#endif