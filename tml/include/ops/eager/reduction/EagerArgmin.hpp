#pragma once

#include "../../lazy/Expr.hpp"
#include "../ExecutionPolicy.hpp"
#include "../serial/SerialArgmin.hpp"
#include "../parallel/ParallelArgmin.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE Scalar argmin(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			Scalar result;
			details::backend::argmin_backend<Scalar, Backend>::argmin(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE Scalar argmin(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			const tml::matrix<Scalar> matrix = expr;
			Scalar result;
			details::backend::argmin_backend<Scalar, Backend>::argmin(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> argmin_rows(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, matrix.rows() });
			details::backend::argmin_backend<Scalar, Backend>::rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> argmin_rows(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, expr.shape.rows });
			const tml::matrix<Scalar> matrix = expr;
			details::backend::argmin_backend<Scalar, Backend>::rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> argmin_columns(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, matrix.columns() });
			details::backend::argmin_backend<Scalar, Backend>::columns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> argmin_columns(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, expr.shape.columns });
			const tml::matrix<Scalar> matrix = expr;
			details::backend::argmin_backend<Scalar, Backend>::columns(matrix, result);
			return result;
		}
	}
}