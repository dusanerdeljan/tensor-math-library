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
				struct MeanBackend<Scalar, OMP>
				{
					TML_STRONG_INLINE void Mean(const tml::Matrix<Scalar>& matrix, Scalar& result)
					{
						std::cout << "running omp backend" << std::endl;
						omp_set_num_threads(tml::HardawreConcurrency);
						Scalar sum = static_cast<Scalar>(0);
						#pragma omp parallel for reduction (+:sum)
						for (int64_t i = 0; i < (int64_t)matrix.Size(); ++i)
							sum += matrix[i];
						result = static_cast<Scalar>(sum / matrix.Size());
					}

					TML_STRONG_INLINE void Rows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						std::cout << "running omp backend" << std::endl;
						omp_set_num_threads(tml::HardawreConcurrency);
						int64_t rows = (int64_t)matrix.Rows(), cols = (int64_t)matrix.Columns();
#						pragma omp parallel for
						for (int64_t i = 0; i < rows; ++i)
							result[i] = static_cast<Scalar>(std::accumulate(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols, static_cast<Scalar>(0)) / cols);
					}

					TML_STRONG_INLINE void Columns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						std::cout << "running omp backend" << std::endl;
						omp_set_num_threads(tml::HardawreConcurrency);
						int64_t rows = (int64_t)matrix.Rows(), cols = (int64_t)matrix.Columns();
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
