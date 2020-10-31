#pragma once

#include "Expr.hpp"
#include "TransposeExpr.hpp"
#include "../../matrix/Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		expr_op<Scalar, transpose_expr<Scalar, typename tml::matrix<Scalar>::const_iterator>>
			transpose(const tml::matrix<Scalar>& matrix)
		{
			typedef transpose_expr<Scalar, typename tml::matrix<Scalar>::const_iterator> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(matrix.cbegin(), matrix.rows(), matrix.columns()), matrix.get_shape().transpose());
		}

		template<typename Scalar, typename T>
		expr_op<Scalar, transpose_expr<Scalar, expr_op<Scalar, T>>>
			transpose(const expr_op<Scalar, T>& expr)
		{
			typedef transpose_expr<Scalar, expr_op<Scalar, T>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(expr, expr.shape.rows, expr.shape.columns), expr.shape.transpose());
		}
	}
}