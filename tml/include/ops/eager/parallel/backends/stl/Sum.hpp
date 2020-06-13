#pragma once

#if TML_HAS_CPP17_STL
#include <execution>
#include "../../../base/SumBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct SumBackend<Scalar, STL>
				{
					TML_STRONG_INLINE void Sum(const tml::Matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("stl");
						result = std::reduce(std::execution::par, matrix.cbegin(), matrix.cend(), static_cast<Scalar>(0));
					}

					TML_STRONG_INLINE void Rows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t i = 0; i < rows; ++i)
							result[i] = std::reduce(matrix.cbegin() + i * cols, matrix.cbegin() + (i + 1) * cols, static_cast<Scalar>(0));
					}

					TML_STRONG_INLINE void Columns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("stl");
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						for (size_t j = 0; j < cols; ++j)
						{
							Scalar colSum = static_cast<Scalar>(0);
							for (size_t i = 0; i < rows; ++i)
								colSum += matrix[j + i * cols];
							result[j] = colSum;
						}
					}
				};
			}
		}
	}
}
#endif
