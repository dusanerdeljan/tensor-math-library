#pragma once

#include "../../Assert.hpp"
#include "../LazyOPs.hpp"
#include "../Expr.hpp"
#include "../BinaryOP.hpp"
#include "../ScalarExpr.hpp"
#include "../ReshapeOP.hpp"
#include "../../../matrix/Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		expr_op<Scalar, reshape_op<Scalar, typename tml::matrix<Scalar>::const_iterator>>
			reshape(const tml::matrix<Scalar>& matrix, const shape& shape)
		{
			TML_ASSERT_RESHAPE(matrix, shape);
			typedef reshape_op<Scalar, typename tml::matrix<Scalar>::const_iterator> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(matrix.cbegin()), shape);
		}

		template<typename Scalar, typename T>
		expr_op<Scalar, reshape_op<Scalar, expr_op<Scalar, T>>>
			reshape(const expr_op<Scalar, T>& expr, const shape& shape)
		{
			TML_ASSERT_RESHAPE(expr, shape);
			typedef reshape_op<Scalar, expr_op<Scalar, T>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(expr), shape);
		}
	}
}