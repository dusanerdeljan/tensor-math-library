#pragma once

#include <algorithm>
#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar>
			void SerialMinAll(const tml::Matrix<Scalar>& matrix, Scalar& result)
			{
				result = *std::min_element(matrix.cbegin(), matrix.cend());
			}

			template<typename Scalar>
			void SerialMinRows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				for (size_t i = 0; i < rows; ++i)
					result[i] = *std::min_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols);
			}

			template<typename Scalar>
			void SerialMinColumns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				const tml::Matrix<Scalar> transposed = tml::eager::Transpose(matrix, tml::SERIAL);
				for (size_t i = 0; i < cols; ++i)
					result[i] = *std::min_element(transposed.cbegin() + i*rows, transposed.cbegin() + (i + 1)*rows);
			}
		}
	}
}