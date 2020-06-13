#pragma once

#if TML_HAS_CPP17_STL
#include <execution>
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
				struct MeanBackend<Scalar, STL>
				{
					TML_STRONG_INLINE void Mean(const tml::Matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("stl");
						result = static_cast<Scalar>(std::reduce(std::execution::par, matrix.cbegin(), matrix.cend(), static_cast<Scalar>(0)) / matrix.Size());
					}

					TML_STRONG_INLINE void Rows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t i = 0; i < rows; ++i)
							result[i] = static_cast<Scalar>(std::reduce(matrix.cbegin() + i * cols, matrix.cbegin() + (i + 1) * cols, static_cast<Scalar>(0)) / cols);
					}

					TML_STRONG_INLINE void Columns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t j = 0; j < cols; ++j)
						{
							Scalar colMean = static_cast<Scalar>(0);
							for (size_t i = 0; i < rows; ++i)
								colMean += matrix[j + i * cols];
							result[j] = static_cast<Scalar>(colMean / rows);;
						}
					}
				};
			}
		}
	}
}
#endif
