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
				struct TransposeBackend<Scalar, STL>
				{
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						const size_t blockSize = 32;
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						const int rowTiles = 1 + ((rows-1)/blockSize);
						const int colTiles = 1 + ((cols-1)/blockSize);
						const Counter rowCounter(0, rowTiles);
						const Counter columnCounter(0, colTiles);
						std::for_each(std::execution::par, rowCounter.begin(), rowCounter.end(), [&](int i) {
							std::for_each(std::execution::par, columnCounter.begin(), columnCounter.end(), [&](int j) {
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
