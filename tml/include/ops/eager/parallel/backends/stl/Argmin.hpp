#pragma once

#if TML_HAS_CPP17_STL
#include <execution>
#include "../../../base/ArgminBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct ArgminBackend<Scalar, STL>
				{
					TML_STRONG_INLINE void Argmin(const tml::Matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("stl");
						result = static_cast<Scalar>(std::min_element(std::execution::par, matrix.cbegin(), matrix.cend()) - matrix.cbegin());
					}

					TML_STRONG_INLINE void Rows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t i = 0; i < rows; ++i)
							result[i] = static_cast<Scalar>(std::min_element(matrix.cbegin() + i * cols, matrix.cbegin() + (i + 1) * cols) - (matrix.cbegin() + i * cols));
					}

					TML_STRONG_INLINE void Columns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t j = 0; j < cols; ++j)
						{
							Scalar colArgmin = static_cast<Scalar>(0);
							for (size_t i = 0; i < rows; ++i)
								if (matrix[j + i * cols] < matrix[j + colArgmin * cols])
									colArgmin = static_cast<Scalar>(i);
							result[j] = colArgmin;
						}
					}
				};
			}
		}
	}
}
#endif
