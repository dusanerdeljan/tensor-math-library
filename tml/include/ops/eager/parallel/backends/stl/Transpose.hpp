#pragma once

#if TML_HAS_CPP17_STL
#include "../../../base/TransposeBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct transpose_backend<Scalar, STL>
				{
					TML_STRONG_INLINE void do_op(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						const size_t blockSize = 32;
						size_t rows = matrix.rows(), cols = matrix.columns();
						const size_t rowTiles = 1 + ((rows-1)/blockSize);
						const size_t colTiles = 1 + ((cols-1)/blockSize);
						const counter<size_t> rowCounter(0, rowTiles);
						const counter<size_t> columnCounter(0, colTiles);
						std::for_each(std::execution::par, rowCounter.begin(), rowCounter.end(), [&](size_t i) {
							std::for_each(std::execution::par, columnCounter.begin(), columnCounter.end(), [&](size_t j) {
								for (size_t br = 0; br < blockSize && i*blockSize + br < rows; ++br)
									for (size_t bc = 0; bc < blockSize && j*blockSize + bc < cols; ++bc)
										result[i*blockSize + br + (j*blockSize + bc) * rows] = matrix[j*blockSize + bc + (i*blockSize + br) * cols];
							});
						});
					}
				};
			}
		}
	}
}
#endif
