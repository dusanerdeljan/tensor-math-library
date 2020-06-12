#pragma once

#include "../base/MeanBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct MeanBackend<Scalar, SEQ>
				{
					TML_STRONG_INLINE void Mean(const tml::Matrix<Scalar>& matrix, Scalar& result)
					{
						std::cout << "running seq backend" << std::endl;
						result = static_cast<Scalar>(std::accumulate(matrix.cbegin(), matrix.cend(), static_cast<Scalar>(0)) / matrix.Size());
					}

					TML_STRONG_INLINE void Rows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						std::cout << "running seq backend" << std::endl;
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t i = 0; i < rows; ++i)
							result[i] = static_cast<Scalar>(std::accumulate(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols, static_cast<Scalar>(0)) / cols);
					}

					TML_STRONG_INLINE void Columns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						std::cout << "running seq backend" << std::endl;
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t j = 0; j < cols; ++j)
						{
							Scalar colMean = static_cast<Scalar>(0);
							for (size_t i = 0; i < rows; ++i)
								colMean += matrix[j + i*cols];
							result[j] = static_cast<Scalar>(colMean / rows);
						}
					}
				};
			}
		}
	}
}
