#pragma once

#include "Expr.hpp"
#include "TransposeExpr.hpp"
#include "..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		ExprOP<Scalar, TransposeExpr<Scalar, typename tml::Matrix<Scalar>::const_iterator>>
			Transpose(const tml::Matrix<Scalar>& matrix)
		{
			typedef TransposeExpr<Scalar, typename tml::Matrix<Scalar>::const_iterator> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix.cbegin(), matrix.Rows(), matrix.Columns()), matrix.GetShape().Transpose());
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, TransposeExpr<Scalar, ExprOP<Scalar, T>>>
			Transpose(const ExprOP<Scalar, T>& expr)
		{
			typedef TransposeExpr<Scalar, ExprOP<Scalar, T>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr, expr.shape.Rows, expr.shape.Columns), expr.shape.Transpose());
		}
	}
}