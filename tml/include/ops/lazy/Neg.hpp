#pragma once

#include "LazyOPs.hpp"
#include "Expr.hpp"
#include "UnaryOP.hpp"
#include "ScalarExpr.hpp"
#include "..\..\matrix\Matrix.hpp"

template<typename Scalar>
ExprOP<Scalar, UnaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::NegOP<Scalar>>>
operator - (const tml::Matrix<Scalar>& matrix)
{
	typedef UnaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::NegOP<Scalar>> ExprType;
	return ExprOP<Scalar, ExprType>(ExprType(matrix.cbegin()), matrix.GetShape());
}

template<typename Scalar, typename T>
ExprOP<Scalar, UnaryOP<Scalar, ExprOP<Scalar, T>, tml::lazy::NegOP<Scalar>>>
operator - (const ExprOP<Scalar, T>& expr)
{
	typedef UnaryOP<Scalar, ExprOP<Scalar, T>, tml::lazy::NegOP<Scalar>> ExprType;
	return ExprOP<Scalar, ExprType>(ExprType(expr), expr.shape);
}