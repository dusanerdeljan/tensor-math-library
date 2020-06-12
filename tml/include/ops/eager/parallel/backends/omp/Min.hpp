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
				struct MinBackend<Scalar, OMP>
				{
					TML_STRONG_INLINE void Min(const tml::Matrix<Scalar>& matrix, Scalar& result)
					{
						std::cout << "running omp backend" << std::endl;
						omp_set_num_threads(tml::HardawreConcurrency);
						// Visual studio supports only OpenMP 2.0 and therefore does not support 'min' reduction operator...
						Scalar minVal = std::numeric_limits<Scalar>::max();
						#pragma omp parallel
						{
							Scalar localMin = std::numeric_limits<Scalar>::max();
							#pragma omp for
							for (int64_t i = 0; i < (int64_t)matrix.Size(); ++i)
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

					TML_STRONG_INLINE void Rows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						std::cout << "running omp backend" << std::endl;
						omp_set_num_threads(tml::HardawreConcurrency);
						int64_t rows = (int64_t)matrix.Rows(), cols = (int64_t)matrix.Columns();
						#pragma omp parallel for
						for (int64_t i = 0; i < rows; ++i)
							result[i] = *std::min_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols);
					}

					TML_STRONG_INLINE void Columns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						std::cout << "running omp backend" << std::endl;
						omp_set_num_threads(tml::HardawreConcurrency);
						int64_t rows = (int64_t)matrix.Rows(), cols = (int64_t)matrix.Columns();
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
