#pragma once

#include "../base/ArgmaxBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct ArgmaxBackend<Scalar, SEQ>
				{
					TML_STRONG_INLINE void Argmax(const tml::Matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("seq");
						result = static_cast<Scalar>(std::max_element(matrix.cbegin(), matrix.cend()) - matrix.cbegin());
					}

					TML_STRONG_INLINE void Rows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("seq");
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t i = 0; i < rows; ++i)
							result[i] = static_cast<Scalar>(std::max_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols) - (matrix.cbegin() + i*cols));
					}

					TML_STRONG_INLINE void Columns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("seq");
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t j = 0; j < cols; ++j)
						{
							Scalar colArgmax = static_cast<Scalar>(0);
							for (size_t i = 0; i < rows; ++i)
								if (matrix[j + i*cols] > matrix[j + colArgmax*cols])
									colArgmax = static_cast<Scalar>(i);
							result[j] = colArgmax;
						}
					}
				};
			}
		}
	}
}
