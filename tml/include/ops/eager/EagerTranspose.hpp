#pragma once

#include "ExecutionPolicy.hpp"
#include "serial/SerialTranspose.hpp"
#include "parallel/ParallelTranspose.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> transpose(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(tml::shape{ matrix.columns(), matrix.rows() });
			details::backend::transpose_backend<Scalar, Backend>::do_op(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> transpose(const expr_op<Scalar, T> expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(tml::shape{ matrix.columns(), matrix.rows() });
			details::backend::transpose_backend<Scalar, Backend>::do_op(matrix, result);
			return result;
		}
	}
}