#pragma once

#include <numeric>
#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar>
			void SerialSumAll(const tml::Matrix<Scalar>& matrix, Scalar& result)
			{
				result = std::accumulate(matrix.cbegin(), matrix.cend(), static_cast<Scalar>(0));
			}

			template<typename Scalar>
			void SerialSumRows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				for (size_t i = 0; i < rows; ++i)
					result[i] = std::accumulate(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols, static_cast<Scalar>(0));
			}

			template<typename Scalar>
			void SerialSumColumns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				for (size_t j = 0; j < cols; ++j)
				{
					Scalar temp = static_cast<Scalar>(0);
					for (size_t i = 0; i < rows; ++i)
						temp += matrix(i, j);
					result[j] = temp;
				}
			}
		}
	}
}
