#pragma once

#include "../../Assert.hpp"
#include "../LazyOPs.hpp"
#include "../Expr.hpp"
#include "../BinaryOP.hpp"
#include "../ScalarExpr.hpp"
#include "../../../matrix/Matrix.hpp"

template<typename Scalar>
expr_op<Scalar, binary_op<Scalar, typename tml::matrix<Scalar>::const_iterator, typename tml::matrix<Scalar>::const_iterator, tml::lazy::mul_op<Scalar>>>
operator * (const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right)
{
	TML_ASSERT_SHAPE(left, right);
	typedef binary_op<Scalar, typename tml::matrix<Scalar>::const_iterator, typename tml::matrix<Scalar>::const_iterator, tml::lazy::mul_op<Scalar>> ExprType;
	return expr_op<Scalar, ExprType>(ExprType(left.cbegin(), right.cbegin()), left.get_shape());
}

template<typename Scalar, typename T>
expr_op<Scalar, binary_op<Scalar, typename tml::matrix<Scalar>::const_iterator, expr_op<Scalar, T>, tml::lazy::mul_op<Scalar>>>
operator * (const tml::matrix<Scalar>& left, const expr_op<Scalar, T>& right)
{
	TML_ASSERT_SHAPE(left, right);
	typedef binary_op<Scalar, typename tml::matrix<Scalar>::const_iterator, expr_op<Scalar, T>, tml::lazy::mul_op<Scalar>> ExprType;
	return expr_op<Scalar, ExprType>(ExprType(left.cbegin(), right), right.shape);
}

template<typename Scalar, typename T>
expr_op<Scalar, binary_op<Scalar, expr_op<Scalar, T>, typename tml::matrix<Scalar>::const_iterator, tml::lazy::mul_op<Scalar>>>
operator * (const expr_op<Scalar, T>& left, const tml::matrix<Scalar>& right)
{
	TML_ASSERT_SHAPE(left, right);
	typedef binary_op<Scalar, expr_op<Scalar, T>, typename tml::matrix<Scalar>::const_iterator, tml::lazy::mul_op<Scalar>> ExprType;
	return expr_op<Scalar, ExprType>(ExprType(left, right.cbegin()), left.shape);
}

template<typename Scalar, typename Left, typename Right>
expr_op<Scalar, binary_op<Scalar, expr_op<Scalar, Left>, expr_op<Scalar, Right>, tml::lazy::mul_op<Scalar>>>
operator * (const expr_op<Scalar, Left>& left, const expr_op<Scalar, Right>& right)
{
	TML_ASSERT_SHAPE(left, right);
	typedef binary_op<Scalar, expr_op<Scalar, Left>, expr_op<Scalar, Right>, tml::lazy::mul_op<Scalar>> ExprType;
	return expr_op<Scalar, ExprType>(ExprType(left, right), left.shape);
}

template<typename Scalar>
expr_op<Scalar, binary_op<Scalar, scalar_expr<Scalar>, typename tml::matrix<Scalar>::const_iterator, tml::lazy::mul_op<Scalar>>>
operator *(Scalar left, const tml::matrix<Scalar>& right)
{
	typedef binary_op<Scalar, scalar_expr<Scalar>, typename tml::matrix<Scalar>::const_iterator, tml::lazy::mul_op<Scalar>> ExprType;
	return expr_op<Scalar, ExprType>(ExprType(left, right.cbegin()), right.get_shape());
}

template<typename Scalar>
expr_op<Scalar, binary_op<Scalar, typename tml::matrix<Scalar>::const_iterator, scalar_expr<Scalar>, tml::lazy::mul_op<Scalar>>>
operator *(const tml::matrix<Scalar>& left, Scalar right)
{
	typedef binary_op<Scalar, typename tml::matrix<Scalar>::const_iterator, scalar_expr<Scalar>, tml::lazy::mul_op<Scalar>> ExprType;
	return expr_op<Scalar, ExprType>(ExprType(left.cbegin(), right), left.get_shape());
}

template<typename Scalar, typename T>
expr_op<Scalar, binary_op<Scalar, expr_op<Scalar, T>, scalar_expr<Scalar>, tml::lazy::mul_op<Scalar>>>
operator *(const expr_op<Scalar, T>& left, Scalar right)
{
	typedef binary_op<Scalar, expr_op<Scalar, T>, scalar_expr<Scalar>, tml::lazy::mul_op<Scalar>> ExprType;
	return expr_op<Scalar, ExprType>(ExprType(left, right), left.shape);
}

template<typename Scalar, typename T>
expr_op<Scalar, binary_op<Scalar, scalar_expr<Scalar>, expr_op<Scalar, T>, tml::lazy::mul_op<Scalar>>>
operator *(Scalar left, const expr_op<Scalar, T>& right)
{
	typedef binary_op<Scalar, scalar_expr<Scalar>, expr_op<Scalar, T>, tml::lazy::mul_op<Scalar>> ExprType;
	return expr_op<Scalar, ExprType>(ExprType(left, right), right.shape);
}

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		Scalar mul(Scalar left, Scalar right)
		{
			return mul_op<Scalar>::op(left, right);
		}

		template<typename Scalar>
		expr_op<Scalar, binary_op<Scalar, typename tml::matrix<Scalar>::const_iterator, typename tml::matrix<Scalar>::const_iterator, tml::lazy::mul_op<Scalar>>>
			mul(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef binary_op<Scalar, typename tml::matrix<Scalar>::const_iterator, typename tml::matrix<Scalar>::const_iterator, tml::lazy::mul_op<Scalar>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left.cbegin(), right.cbegin()), left.get_shape());
		}

		template<typename Scalar, typename T>
		expr_op<Scalar, binary_op<Scalar, typename tml::matrix<Scalar>::const_iterator, expr_op<Scalar, T>, tml::lazy::mul_op<Scalar>>>
			mul(const tml::matrix<Scalar>& left, const expr_op<Scalar, T>& right)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef binary_op<Scalar, typename tml::matrix<Scalar>::const_iterator, expr_op<Scalar, T>, tml::lazy::mul_op<Scalar>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left.cbegin(), right), right.shape);
		}

		template<typename Scalar, typename T>
		expr_op<Scalar, binary_op<Scalar, expr_op<Scalar, T>, typename tml::matrix<Scalar>::const_iterator, tml::lazy::mul_op<Scalar>>>
			mul(const expr_op<Scalar, T>& left, const tml::matrix<Scalar>& right)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef binary_op<Scalar, expr_op<Scalar, T>, typename tml::matrix<Scalar>::const_iterator, tml::lazy::mul_op<Scalar>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left, right.cbegin()), left.shape);
		}

		template<typename Scalar, typename Left, typename Right>
		expr_op<Scalar, binary_op<Scalar, expr_op<Scalar, Left>, expr_op<Scalar, Right>, tml::lazy::mul_op<Scalar>>>
			mul(const expr_op<Scalar, Left>& left, const expr_op<Scalar, Right>& right)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef binary_op<Scalar, expr_op<Scalar, Left>, expr_op<Scalar, Right>, tml::lazy::mul_op<Scalar>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left, right), left.shape);
		}

		template<typename Scalar>
		expr_op<Scalar, binary_op<Scalar, scalar_expr<Scalar>, typename tml::matrix<Scalar>::const_iterator, tml::lazy::mul_op<Scalar>>>
			mul(Scalar left, const tml::matrix<Scalar>& right)
		{
			typedef binary_op<Scalar, scalar_expr<Scalar>, typename tml::matrix<Scalar>::const_iterator, tml::lazy::mul_op<Scalar>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left, right.cbegin()), right.get_shape());
		}

		template<typename Scalar>
		expr_op<Scalar, binary_op<Scalar, typename tml::matrix<Scalar>::const_iterator, scalar_expr<Scalar>, tml::lazy::mul_op<Scalar>>>
			mul(const tml::matrix<Scalar>& left, Scalar right)
		{
			typedef binary_op<Scalar, typename tml::matrix<Scalar>::const_iterator, scalar_expr<Scalar>, tml::lazy::mul_op<Scalar>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left.cbegin(), right), left.get_shape());
		}

		template<typename Scalar, typename T>
		expr_op<Scalar, binary_op<Scalar, expr_op<Scalar, T>, scalar_expr<Scalar>, tml::lazy::mul_op<Scalar>>>
			mul(const expr_op<Scalar, T>& left, Scalar right)
		{
			typedef binary_op<Scalar, expr_op<Scalar, T>, scalar_expr<Scalar>, tml::lazy::mul_op<Scalar>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left, right), left.shape);
		}

		template<typename Scalar, typename T>
		expr_op<Scalar, binary_op<Scalar, scalar_expr<Scalar>, expr_op<Scalar, T>, tml::lazy::mul_op<Scalar>>>
			mul(Scalar left, const expr_op<Scalar, T>& right)
		{
			typedef binary_op<Scalar, scalar_expr<Scalar>, expr_op<Scalar, T>, tml::lazy::mul_op<Scalar>> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left, right), right.shape);
		}
	}
}