#pragma once

#include "../Expr.hpp"
#include "../ReductionExpr.hpp"
#include "../LazyOPs.hpp"
#include "../../eager/reduction/EagerSum.hpp"
#include "../../../matrix/Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		Scalar sum(const tml::matrix<Scalar>& matrix)
		{
			return tml::eager::sum(matrix);
		}

		template<typename Scalar, typename T>
		Scalar sum(const expr_op<Scalar, T>& expr)
		{
			return tml::eager::sum(expr);
		}

		template<typename Scalar>
		expr_op<Scalar, reduction_expr<Scalar, tml::matrix<Scalar>, sum_rows_op<Scalar, tml::matrix<Scalar>>>>
			sum_rows(const tml::matrix<Scalar>& matrix)
		{
			typedef reduction_expr<Scalar, tml::matrix<Scalar>, sum_rows_op<Scalar, tml::matrix<Scalar>>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(matrix), { 1, matrix.rows() });
		}

		template<typename Scalar, typename T>
		expr_op<Scalar, reduction_expr<Scalar, expr_op<Scalar, T>, sum_rows_op<Scalar, expr_op<Scalar, T>>>>
			sum_rows(const expr_op<Scalar, T>& expr)
		{
			typedef reduction_expr<Scalar, expr_op<Scalar, T>, sum_rows_op<Scalar, expr_op<Scalar, T>>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(expr), { 1, expr.rows() });
		}

		template<typename Scalar>
		expr_op<Scalar, reduction_expr<Scalar, tml::matrix<Scalar>, sum_cols_op<Scalar, tml::matrix<Scalar>>>>
			sum_columns(const tml::matrix<Scalar>& matrix)
		{
			typedef reduction_expr<Scalar, tml::matrix<Scalar>, sum_cols_op<Scalar, tml::matrix<Scalar>>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(matrix), { 1, matrix.columns() });
		}

		template<typename Scalar, typename T>
		expr_op<Scalar, reduction_expr<Scalar, expr_op<Scalar, T>, sum_cols_op<Scalar, expr_op<Scalar, T>>>>
			sum_columns(const expr_op<Scalar, T>& expr)
		{
			typedef reduction_expr<Scalar, expr_op<Scalar, T>, sum_cols_op<Scalar, expr_op<Scalar, T>>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(expr), { 1, expr.columns() });
		}
	}
}
