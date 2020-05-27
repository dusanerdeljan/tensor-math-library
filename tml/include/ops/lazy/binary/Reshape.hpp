#pragma once

#include "..\..\Assert.hpp"
#include "..\LazyOPs.hpp"
#include "..\Expr.hpp"
#include "..\BinaryOP.hpp"
#include "..\ScalarExpr.hpp"
#include "..\ReshapeOP.hpp"
#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		ExprOP<Scalar, ReshapeOP<Scalar, typename tml::Matrix<Scalar>::const_iterator>>
			Reshape(const tml::Matrix<Scalar>& matrix, const Shape& shape)
		{
			TML_ASSERT_RESHAPE(matrix, shape);
			typedef ReshapeOP<Scalar, typename tml::Matrix<Scalar>::const_iterator> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix.cbegin()), shape);
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, ReshapeOP<Scalar, ExprOP<Scalar, T>>>
			Reshape(const ExprOP<Scalar, T>& expr, const Shape& shape)
		{
			TML_ASSERT_RESHAPE(expr, shape);
			typedef ReshapeOP<Scalar, ExprOP<Scalar, T>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), shape);
		}
	}
}