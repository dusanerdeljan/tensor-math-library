#pragma once

#include "../Expr.hpp"
#include "../ReductionExpr.hpp"
#include "../LazyOPs.hpp"
#include "../../eager/reduction/EagerArgmin.hpp"
#include "../../../matrix/Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		Scalar argmin(const tml::matrix<Scalar>& matrix)
		{
			return tml::eager::argmin(matrix);
		}

		template<typename Scalar, typename T>
		Scalar argmin(const expr_op<Scalar, T>& expr)
		{
			return tml::eager::argmin(expr);
		}

		template<typename Scalar>
		expr_op<Scalar, reduction_expr<Scalar, tml::matrix<Scalar>, argmin_rows_op<Scalar, tml::matrix<Scalar>>>>
			argmin_rows(const tml::matrix<Scalar>& matrix)
		{
			typedef reduction_expr<Scalar, tml::matrix<Scalar>, argmin_rows_op<Scalar, tml::matrix<Scalar>>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(matrix), { 1, matrix.rows() });
		}

		template<typename Scalar, typename T>
		expr_op<Scalar, reduction_expr<Scalar, expr_op<Scalar, T>, argmin_rows_op<Scalar, expr_op<Scalar, T>>>>
			argmin_rows(const expr_op<Scalar, T>& expr)
		{
			typedef reduction_expr<Scalar, expr_op<Scalar, T>, argmin_rows_op<Scalar, expr_op<Scalar, T>>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(expr), { 1, expr.rows() });
		}

		template<typename Scalar>
		expr_op<Scalar, reduction_expr<Scalar, tml::matrix<Scalar>, argmin_cols_op<Scalar, tml::matrix<Scalar>>>>
			argmin_columns(const tml::matrix<Scalar>& matrix)
		{
			typedef reduction_expr<Scalar, tml::matrix<Scalar>, argmin_cols_op<Scalar, tml::matrix<Scalar>>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(matrix), { 1, matrix.columns() });
		}

		template<typename Scalar, typename T>
		expr_op<Scalar, reduction_expr<Scalar, expr_op<Scalar, T>, argmin_cols_op<Scalar, expr_op<Scalar, T>>>>
			argmin_columns(const expr_op<Scalar, T>& expr)
		{
			typedef reduction_expr<Scalar, expr_op<Scalar, T>, argmin_cols_op<Scalar, expr_op<Scalar, T>>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(expr), { 1, expr.columns() });
		}
	}
}
