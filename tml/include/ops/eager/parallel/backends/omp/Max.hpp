#pragma once

#if TML_HAS_OMP
#undef min
#undef max
#include <omp.h>
#include "../../../base/MaxBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct max_backend<Scalar, OMP>
				{
					TML_STRONG_INLINE void max(const tml::matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						// Visual studio supports only OpenMP 2.0 and therefore does not support 'max' reduction operator...
						Scalar maxVal = std::numeric_limits<Scalar>::min();
						#pragma omp parallel
						{
							Scalar localMax = std::numeric_limits<Scalar>::min();
							#pragma omp for
							for (int64_t i = 0; i < (int64_t)matrix.size(); ++i)
							{
								if (matrix[i] > localMax)
									localMax = matrix[i];
							}
							#pragma omp critical
							{
								if (localMax > maxVal)
									maxVal = localMax;
							}
						}
						result = maxVal;
					}

					TML_STRONG_INLINE void rows(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						int64_t rows = (int64_t)matrix.rows(), cols = (int64_t)matrix.columns();
						#pragma omp parallel for
						for (int64_t i = 0; i < rows; ++i)
							result[i] = *std::max_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols);
					}

					TML_STRONG_INLINE void columns(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						int64_t rows = (int64_t)matrix.rows(), cols = (int64_t)matrix.columns();
						#pragma omp parallel for
						for (int64_t j = 0; j < cols; ++j)
						{
							Scalar colMax = std::numeric_limits<Scalar>::min();
							for (int64_t i = 0; i < rows; ++i)
								if (matrix[j + i*cols] > colMax)
									colMax = matrix[j + i*cols];
							result[j] = colMax;
						}
					}
				};
			}
		}
	}
}
#endif
