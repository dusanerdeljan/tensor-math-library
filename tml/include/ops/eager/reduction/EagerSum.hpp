#pragma once

#include "../../lazy/Expr.hpp"
#include "../ExecutionPolicy.hpp"
#include "../serial/SerialSum.hpp"
#include "../parallel/ParallelSum.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE Scalar sum(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			Scalar result;
			details::backend::sum_backend<Scalar, Backend>::sum(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE Scalar sum(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			const tml::matrix<Scalar> matrix = expr;
			Scalar result;
			details::backend::sum_backend<Scalar, Backend>::sum(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> sum_rows(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, matrix.rows() });
			details::backend::sum_backend<Scalar, Backend>::rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> sum_rows(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, expr.shape.rows});
			const tml::matrix<Scalar> matrix = expr;
			details::backend::sum_backend<Scalar, Backend>::rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> sum_columns(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, matrix.columns() });
			details::backend::sum_backend<Scalar, Backend>::columns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> sum_columns(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, expr.shape.columns });
			const tml::matrix<Scalar> matrix = expr;
			details::backend::sum_backend<Scalar, Backend>::columns(matrix, result);
			return result;
		}
	}
}