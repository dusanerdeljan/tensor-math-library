#pragma once

#include "../base/MaxBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct MaxBackend<Scalar, SEQ>
				{
					TML_STRONG_INLINE void Max(const tml::Matrix<Scalar>& matrix, Scalar& result)
					{
						std::cout << "running seq backend" << std::endl;
						result = *std::max_element(matrix.cbegin(), matrix.cend());
					}

					TML_STRONG_INLINE void Rows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						std::cout << "running seq backend" << std::endl;
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t i = 0; i < rows; ++i)
							result[i] = *std::max_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols);
					}

					TML_STRONG_INLINE void Columns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						std::cout << "running seq backend" << std::endl;
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t j = 0; j < cols; ++j)
						{
							Scalar colMax = std::numeric_limits<Scalar>::lowest();
								for (size_t i = 0; i < rows; ++i)
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
