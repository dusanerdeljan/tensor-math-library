#pragma once

#include "..\LazyOPs.hpp"
#include "..\Expr.hpp"
#include "..\UnaryOP.hpp"
#include "..\ScalarExpr.hpp"
#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		Scalar Cosh(Scalar scalar)
		{
			return CoshOP<Scalar>::op(scalar);
		}

		template<typename Scalar>
		ExprOP<Scalar, UnaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, CoshOP<Scalar>>>
			Cosh(const tml::Matrix<Scalar>& matrix)
		{
			typedef UnaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, CoshOP<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix.cbegin()), matrix.GetShape());
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, UnaryOP<Scalar, ExprOP<Scalar, T>, CoshOP<Scalar>>>
			Cosh(const ExprOP<Scalar, T>& expr)
		{
			typedef UnaryOP<Scalar, ExprOP<Scalar, T>, CoshOP<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), expr.shape);
		}
	}
}