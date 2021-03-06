#pragma once

#if TML_HAS_OMP
#undef min
#undef max
#include <omp.h>
#include "../../../base/ArgmaxBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct argmax_backend<Scalar, OMP>
				{
					TML_STRONG_INLINE void argmax(const tml::matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						int64_t maxVal = omp_get_thread_num();
						#pragma omp parallel
						{
							int64_t localArgmax = 0;
							#pragma omp for
							for (int64_t i = 0; i < (int64_t)matrix.size(); ++i)
							{
								if (matrix[i] > matrix[localArgmax])
									localArgmax = i;
							}
							#pragma omp critical
							{
								if (matrix[localArgmax] > matrix[maxVal])
									maxVal = localArgmax;
							}
						}
						result = static_cast<Scalar>(maxVal);
					}

					TML_STRONG_INLINE void rows(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						int64_t rows = (int64_t)matrix.rows(), cols = (int64_t)matrix.columns();
						#pragma omp parallel for
						for (int64_t i = 0; i < rows; ++i)
							result[i] = static_cast<Scalar>(std::max_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols) - (matrix.cbegin() + i*cols));
					}

					TML_STRONG_INLINE void columns(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						int64_t rows = (int64_t)matrix.rows(), cols = (int64_t)matrix.columns();
						#pragma omp parallel for
						for (int64_t j = 0; j < cols; ++j)
						{
							int64_t colArgmax = 0;
							for (int64_t i = 0; i < rows; ++i)
								if (matrix[j + i*cols] > matrix[j + colArgmax*cols])
									colArgmax = i;
							result[j] = static_cast<Scalar>(colArgmax);
						}
					}
				};
			}
		}
	}
}
#endif
