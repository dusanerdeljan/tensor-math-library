#pragma once

#if TML_HAS_OMP
#include <omp.h>
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
				struct TransposeBackend<Scalar, OMP>
				{
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::HardawreConcurrency);
						int64_t blockSize = 32;
						int64_t rows = matrix.Rows(), cols = matrix.Columns();
						#pragma omp parallel for
						for (int64_t i = 0; i < rows; i += blockSize)
							for (int64_t j = 0; j < cols; j += blockSize)
								for (int64_t br = 0; br < blockSize && i + br < rows; ++br)
									for (int64_t bc = 0; bc < blockSize && j + bc < cols; ++bc)
										result[i + br + (j + bc)*rows] = matrix[j + bc + (i + br)*cols];
					}
				};
			}
		}
	}
}
#endif
