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
				struct matmul_backend<Scalar, STL>
				{
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						const tml::matrix<Scalar> newRight = tml::eager::transpose(right, tml::execution::stl);
						size_t r1 = left.rows(), c1 = left.columns(), r2 = right.rows(), c2 = right.columns();
						// TODO: Calculate tile size like L1_CACHE_LINE_SIZE_BYTES / sizeof(Scalar)
						const size_t rowTiles = 1 + ((r1-1)/32);
						const size_t colTiles = 1 + ((c2-1)/32);
						const counter<size_t> rowCounter(0, rowTiles);
						const counter<size_t> columnCounter(0, colTiles);
						std::for_each(std::execution::par, rowCounter.begin(), rowCounter.end(), [&](size_t i) {
							std::for_each(std::execution::par, columnCounter.begin(), columnCounter.end(), [&](size_t j) {
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
