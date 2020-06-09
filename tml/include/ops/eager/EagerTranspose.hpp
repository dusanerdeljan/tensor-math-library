#pragma once

#include "ExecutionPolicy.hpp"
#include "serial/SerialTranspose.hpp"
#include "parallel/ParallelTranspose.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Transpose(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(tml::Shape{ matrix.Columns(), matrix.Rows() });
			details::backend::TransposeBackend<Scalar, Backend>::DoOP(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Transpose(const ExprOP<Scalar, T> expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(tml::Shape{ matrix.Columns(), matrix.Rows() });
			details::backend::TransposeBackend<Scalar, Backend>::DoOP(matrix, result);
			return result;
		}
	}
}