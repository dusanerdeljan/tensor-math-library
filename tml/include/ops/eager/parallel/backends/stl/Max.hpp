#pragma once

#if TML_HAS_CPP17_STL
#include <execution>
#include "../../../base/MaxBase.hpp"
#include "CountingIterator.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct max_backend<Scalar, STL>
				{
					TML_STRONG_INLINE void max(const tml::matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("stl");
						result = *std::max_element(std::execution::par, matrix.cbegin(), matrix.cend());
					}

					TML_STRONG_INLINE void rows(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						size_t rows = matrix.rows(), cols = matrix.columns();
						Counter cnt(0, rows);
						std::for_each(std::execution::par, cnt.begin(), cnt.end(), [&](int i) {
							result[i] = *std::max_element(matrix.cbegin() + i * cols, matrix.cbegin() + (i + 1) * cols);
						});
					}

					TML_STRONG_INLINE void columns(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						size_t rows = matrix.rows(), cols = matrix.columns();
						for (size_t j = 0; j < cols; ++j)
						{
							Scalar colMax = std::numeric_limits<Scalar>::lowest();
							for (size_t i = 0; i < rows; ++i)
								if (matrix[j + i * cols] > colMax)
									colMax = matrix[j + i * cols];
							result[j] = colMax;
						}
					}
				};
			}
		}
	}
}
#endif
