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
		Scalar Square(Scalar scalar)
		{
			return SquareOP<Scalar>::op(scalar);
		}

		template<typename Scalar>
		ExprOP<Scalar, UnaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, SquareOP<Scalar>>>
			Square(const tml::Matrix<Scalar>& matrix)
		{
			typedef UnaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, SquareOP<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix.cbegin()), matrix.GetShape());
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, UnaryOP<Scalar, ExprOP<Scalar, T>, SquareOP<Scalar>>>
			Square(const ExprOP<Scalar, T>& expr)
		{
			typedef UnaryOP<Scalar, ExprOP<Scalar, T>, SquareOP<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), expr.shape);
		}
	}
}