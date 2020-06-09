#pragma once

#include <numeric>
#include "../../../matrix/Matrix.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar>
			void SerialMeanAll(const tml::Matrix<Scalar>& matrix, Scalar& result)
			{
				result = std::accumulate(matrix.cbegin(), matrix.cend(), static_cast<Scalar>(0)) / matrix.Size();
			}

			template<typename Scalar>
			void SerialMeanRows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				for (size_t i = 0; i < rows; ++i)
					result[i] = std::accumulate(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols, static_cast<Scalar>(0)) / matrix.Columns();
			}

			template<typename Scalar>
			void SerialMeanColumns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				const tml::Matrix<Scalar> transposed = matrix;
				for (size_t i = 0; i < cols; ++i)
					result[i] = std::accumulate(transposed.cbegin() + i*rows, transposed.cbegin() + (i + 1)*rows, static_cast<Scalar>(0)) / matrix.Rows();
			}
		}
	}
}
