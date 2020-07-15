#pragma once

#if TML_HAS_OMP
#include <omp.h>
#include <numeric>
#include "../../../base/MeanBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct mean_backend<Scalar, OMP>
				{
					TML_STRONG_INLINE void mean(const tml::matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						Scalar sum = static_cast<Scalar>(0);
						#pragma omp parallel for reduction (+:sum)
						for (int64_t i = 0; i < (int64_t)matrix.size(); ++i)
							sum += matrix[i];
						result = static_cast<Scalar>(sum / matrix.size());
					}

					TML_STRONG_INLINE void rows(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						int64_t rows = (int64_t)matrix.rows(), cols = (int64_t)matrix.columns();
#						pragma omp parallel for
						for (int64_t i = 0; i < rows; ++i)
							result[i] = static_cast<Scalar>(TML_ACCUMULATE(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols, static_cast<Scalar>(0)) / cols);
					}

					TML_STRONG_INLINE void columns(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("omp");
						omp_set_num_threads(tml::hardware_concurrency);
						int64_t rows = (int64_t)matrix.rows(), cols = (int64_t)matrix.columns();
						#pragma omp parallel for
						for (int64_t j = 0; j < cols; ++j)
						{
							Scalar colMean = static_cast<Scalar>(0);
							for (int64_t i = 0; i < rows; ++i)
								colMean += matrix[j + i*cols];
							result[j] = static_cast<Scalar>(colMean / rows);
						}
					}
				};
			}
		}
	}
}
#endif
