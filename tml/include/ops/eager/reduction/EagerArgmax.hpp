#pragma once

#include "../../lazy/Expr.hpp"
#include "../ExecutionPolicy.hpp"
#include "../serial/SerialArgmax.hpp"
#include "../parallel/ParallelArgmax.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE Scalar argmax(const tml::matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			Scalar result;
			details::backend::argmax_backend<Scalar, Backend>::argmax(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE Scalar argmax(const expr_op<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			const tml::matrix<Scalar> matrix = expr;
			Scalar result;
			details::backend::argmax_backend<Scalar, Backend>::argmax(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> argmax_rows(const tml::matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, matrix.rows() });
			details::backend::argmax_backend<Scalar, Backend>::rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> argmax_rows(const expr_op<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, expr.shape.rows });
			const tml::matrix<Scalar> matrix = expr;
			details::backend::argmax_backend<Scalar, Backend>::rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> argmax_columns(const tml::matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, matrix.columns() });
			details::backend::argmax_backend<Scalar, Backend>::columns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> argmax_columns(const expr_op<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(shape{ 1, expr.shape.columns });
			const tml::matrix<Scalar> matrix = expr;
			details::backend::argmax_backend<Scalar, Backend>::columns(matrix, result);
			return result;
		}
	}
}