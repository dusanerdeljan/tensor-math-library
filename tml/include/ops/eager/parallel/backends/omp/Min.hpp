#pragma once

#if TML_HAS_OMP
#undef min
#undef max
#include <omp.h>
#include "../../../base/MinBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct min_backend<Scalar, OMP>
				{
					TML_STRONG_INLINE void min(const tml::matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						// Visual studio supports only OpenMP 2.0 and therefore does not support 'min' reduction operator...
						Scalar minVal = std::numeric_limits<Scalar>::max();
						#pragma omp parallel
						{
							Scalar localMin = std::numeric_limits<Scalar>::max();
							#pragma omp for
							for (int64_t i = 0; i < (int64_t)matrix.size(); ++i)
							{
								if (matrix[i] < localMin)
									localMin = matrix[i];
							}
							#pragma omp critical
							{
								if (localMin < minVal)
									minVal = localMin;
							}
						}
						result = minVal;
					}

					TML_STRONG_INLINE void rows(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						int64_t rows = (int64_t)matrix.rows(), cols = (int64_t)matrix.columns();
						#pragma omp parallel for
						for (int64_t i = 0; i < rows; ++i)
							result[i] = *std::min_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols);
					}

					TML_STRONG_INLINE void columns(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						int64_t rows = (int64_t)matrix.rows(), cols = (int64_t)matrix.columns();
						#pragma omp parallel for
						for (int64_t j = 0; j < cols; ++j)
						{
							Scalar colMin = std::numeric_limits<Scalar>::max();
							for (int64_t i = 0; i < rows; ++i)
								if (matrix[j + i*cols] < colMin)
									colMin = matrix[j + i*cols];
							result[j] = colMin;
						}
					}
				};
			}
		}
	}
}
#endif
