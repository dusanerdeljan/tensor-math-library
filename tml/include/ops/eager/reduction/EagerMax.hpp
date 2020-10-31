#pragma once

#include "../../lazy/Expr.hpp"
#include "../ExecutionPolicy.hpp"
#include "../serial/SerialMax.hpp"
#include "../parallel/ParallelMax.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE Scalar max(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			Scalar result;
			details::backend::max_backend<Scalar, Backend>::max(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE Scalar max(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			const tml::matrix<Scalar> matrix = expr;
			Scalar result;
			details::backend::max_backend<Scalar, Backend>::max(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> max_rows(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, matrix.rows() });
			details::backend::max_backend<Scalar, Backend>::rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> max_rows(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, expr.shape.rows });
			const tml::matrix<Scalar> matrix = expr;
			details::backend::max_backend<Scalar, Backend>::rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> max_columns(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, matrix.columns() });
			details::backend::max_backend<Scalar, Backend>::columns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> max_columns(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, expr.shape.columns });
			const tml::matrix<Scalar> matrix = expr;
			details::backend::max_backend<Scalar, Backend>::columns(matrix, result);
			return result;
		}
	}
}