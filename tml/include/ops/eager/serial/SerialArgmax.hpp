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
			void SerialArgmaxAll(const tml::Matrix<Scalar>& matrix, Scalar& result)
			{
				result = static_cast<Scalar>(std::max_element(matrix.cbegin(), matrix.cend()) - matrix.cbegin());
			}

			template<typename Scalar>
			void SerialArgmaxRows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				for (size_t i = 0; i < rows; ++i)
					result[i] = static_cast<Scalar>(std::max_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols) - (matrix.cbegin() + i*cols));
			}

			template<typename Scalar>
			void SerialArgmaxColumns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				const tml::Matrix<Scalar> transposed = tml::eager::Transpose(matrix, tml::SERIAL);
				for (size_t i = 0; i < cols; ++i)
					result[i] = static_cast<Scalar>(std::max_element(transposed.cbegin() + i*rows, transposed.cbegin() + (i + 1)*rows) - (transposed.cbegin() + i*rows));
			}
		}
	}
}