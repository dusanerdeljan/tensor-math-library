#pragma once

#if TML_HAS_TBB
#include <tbb/parallel_for.h>
#include "../../../base/UnaryOPBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct TransposeBackend<Scalar, TBB>
				{
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						std::cout << "running tbb backend" << std::endl;
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
				};
			}
		}
	}
}
#endif