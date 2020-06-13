#pragma once

#if TML_HAS_CPP17_STL
#include <execution>
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
				struct MinBackend<Scalar, STL>
				{
					TML_STRONG_INLINE void Min(const tml::Matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("stl");
						result = *std::min_element(std::execution::par, matrix.cbegin(), matrix.cend());
					}

					TML_STRONG_INLINE void Rows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t i = 0; i < rows; ++i)
							result[i] = *std::min_element(matrix.cbegin() + i * cols, matrix.cbegin() + (i + 1) * cols);
					}

					TML_STRONG_INLINE void Columns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						#undef max
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t j = 0; j < cols; ++j)
						{
							Scalar colMin = std::numeric_limits<Scalar>::max();
							for (size_t i = 0; i < rows; ++i)
								if (matrix[j + i * cols] < colMin)
									colMin = matrix[j + i * cols];
							result[j] = colMin;
						}
					}
				};
			}
		}
	}
}
#endif
