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
		ExprOP<Scalar, MatmulExpr<Scalar, tml::Matrix<Scalar>, tml::Matrix<Scalar>>>
			Matmul(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right)
		{
			TML_ASSERT_MATMUL(left, right);
			typedef MatmulExpr<Scalar, tml::Matrix<Scalar>, tml::Matrix<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left, right), { left.Rows(), right.Columns() });
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, MatmulExpr<Scalar, tml::Matrix<Scalar>, ExprOP<Scalar, T>>>
			Matmul(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right)
		{
			TML_ASSERT_MATMUL(left, right);
			typedef MatmulExpr<Scalar, tml::Matrix<Scalar>, ExprOP<Scalar, T>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left, right), { left.Rows(), right.Columns() });
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, MatmulExpr<Scalar, ExprOP<Scalar, T>, tml::Matrix<Scalar>>>
			Matmul(const ExprOP<Scalar, T>& left, const tml::Matrix<Scalar>& right)
		{
			TML_ASSERT_MATMUL(left, right);
			typedef MatmulExpr<Scalar, ExprOP<Scalar, T>, tml::Matrix<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left, right), { left.Rows(), right.Columns() });
		}

		template<typename Scalar, typename Left, typename Right>
		ExprOP<Scalar, MatmulExpr<Scalar, ExprOP<Scalar, Left>, ExprOP<Scalar, Right>>>
			Matmul(const ExprOP<Scalar, Left>& left, const ExprOP<Scalar, Right>& right)
		{
			TML_ASSERT_MATMUL(left, right);
			typedef MatmulExpr<Scalar, ExprOP<Scalar, Left>, ExprOP<Scalar, Right>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left, right), { left.Rows(), right.Columns() });
		}
	}
}
