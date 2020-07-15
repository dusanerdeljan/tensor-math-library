#pragma once

#include "../Assert.hpp"
#include "Expr.hpp"
#include "MatmulExpr.hpp"
#include "../../matrix/Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		expr_op<Scalar, MatmulExpr<Scalar, tml::matrix<Scalar>, tml::matrix<Scalar>>>
			matmul(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right)
		{
			TML_ASSERT_MATMUL(left, right);
			typedef MatmulExpr<Scalar, tml::matrix<Scalar>, tml::matrix<Scalar>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left, right), { left.rows(), right.columns() });
		}

		template<typename Scalar, typename T>
		expr_op<Scalar, MatmulExpr<Scalar, tml::matrix<Scalar>, expr_op<Scalar, T>>>
			matmul(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right)
		{
			TML_ASSERT_MATMUL(left, right);
			typedef MatmulExpr<Scalar, tml::matrix<Scalar>, expr_op<Scalar, T>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left, right), { left.rows(), right.columns() });
		}

		template<typename Scalar, typename T>
		expr_op<Scalar, MatmulExpr<Scalar, expr_op<Scalar, T>, tml::matrix<Scalar>>>
			matmul(const expr_op<Scalar, T>& left, const tml::matrix<Scalar>& right)
		{
			TML_ASSERT_MATMUL(left, right);
			typedef MatmulExpr<Scalar, expr_op<Scalar, T>, tml::matrix<Scalar>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left, right), { left.rows(), right.columns() });
		}

		template<typename Scalar, typename Left, typename Right>
		expr_op<Scalar, MatmulExpr<Scalar, expr_op<Scalar, Left>, expr_op<Scalar, Right>>>
			matmul(const expr_op<Scalar, Left>& left, const expr_op<Scalar, Right>& right)
		{
			TML_ASSERT_MATMUL(left, right);
			typedef MatmulExpr<Scalar, expr_op<Scalar, Left>, expr_op<Scalar, Right>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left, right), { left.rows(), right.columns() });
		}
	}
}
