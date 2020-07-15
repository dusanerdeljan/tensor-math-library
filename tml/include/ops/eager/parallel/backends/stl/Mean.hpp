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
				struct mean_backend<Scalar, STL>
				{
					TML_STRONG_INLINE void mean(const tml::matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("stl");
						result = static_cast<Scalar>(std::reduce(std::execution::par, matrix.cbegin(), matrix.cend(), static_cast<Scalar>(0)) / matrix.size());
					}

					TML_STRONG_INLINE void rows(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						size_t rows = matrix.rows(), cols = matrix.columns();
						for (size_t i = 0; i < rows; ++i)
							result[i] = static_cast<Scalar>(std::reduce(matrix.cbegin() + i * cols, matrix.cbegin() + (i + 1) * cols, static_cast<Scalar>(0)) / cols);
					}

					TML_STRONG_INLINE void columns(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						size_t rows = matrix.rows(), cols = matrix.columns();
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
