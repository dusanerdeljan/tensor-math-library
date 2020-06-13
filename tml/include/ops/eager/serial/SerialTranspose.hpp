#pragma once

#include "../base/TransposeBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details 
		{
			namespace backend
			{
				template<typename Scalar>
				struct TransposeBackend<Scalar, SEQ>
				{
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("seq");
						size_t blockSize = 32;
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t i = 0; i < rows; i += blockSize)
							for (size_t j = 0; j < cols; j += blockSize)
								for (size_t br = 0; br < blockSize && i + br < rows; ++br)
									for (size_t bc = 0; bc < blockSize && j + bc < cols; ++bc)
										result[i + br + (j + bc)*rows] = matrix[j + bc + (i + br)*cols];
					}
				};
			}
		}
	}
}