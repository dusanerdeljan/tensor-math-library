#pragma once

#include <tbb\parallel_for.h>
#include <tbb\blocked_range.h>

#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar>
			void ParallelTranspose(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				int blockSize = 32;
				int rows = static_cast<int>(matrix.Rows()), cols = static_cast<int>(matrix.Columns());
				tbb::parallel_for(0, rows, blockSize, [&](int i)
				{
					for (int j = 0; j < cols; j += blockSize)
						for (int br = 0; br < blockSize && i + br < rows; ++br)
							for (int bc = 0; bc < blockSize && j + bc < cols; ++bc)
								result[i + br + (j + bc)*rows] = matrix[j + bc + (i + br)*cols];
				});
			}
		}
	}
}
