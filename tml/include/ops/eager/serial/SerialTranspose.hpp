#pragma once

#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace eager
	{
		namespace details 
		{
			template<typename Scalar>
			void SerialTranspose(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t blockSize = 32;
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				for (size_t i = 0; i < rows; i += blockSize)
					for (size_t j = 0; j < cols; j += blockSize)
						for (size_t br = 0; br < blockSize && i + br < rows; ++br)
							for (size_t bc = 0; bc < blockSize && j + bc < cols; ++bc)
								result[i + br + (j + bc)*rows] = matrix[j + bc + (i + br)*cols];
			}
		}
	}
}