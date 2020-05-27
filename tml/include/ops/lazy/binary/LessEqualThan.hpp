#pragma once

#include "..\..\Assert.hpp"
#include "..\LazyOPs.hpp"
#include "..\Expr.hpp"
#include "..\BinaryOP.hpp"
#include "..\ScalarExpr.hpp"
#include "..\..\..\matrix\Matrix.hpp"

template<typename Scalar>
ExprOP<Scalar, BinaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::LessEqualThanOP<Scalar>>>
operator <= (const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right)
{
	TML_ASSERT_SHAPE(left, right);
	typedef BinaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
	return ExprOP<Scalar, ExprType>(ExprType(left.cbegin(), right.cbegin()), left.GetShape());
}

template<typename Scalar, typename T>
ExprOP<Scalar, BinaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, ExprOP<Scalar, T>, tml::lazy::LessEqualThanOP<Scalar>>>
operator <= (const tml::Matrix<Scalar>& left, const ExprOP<Scalar, T>& right)
{
	TML_ASSERT_SHAPE(left, right);
	typedef BinaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, ExprOP<Scalar, T>, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
	return ExprOP<Scalar, ExprType>(ExprType(left.cbegin(), right), right.shape);
}

template<typename Scalar, typename T>
ExprOP<Scalar, BinaryOP<Scalar, ExprOP<Scalar, T>, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::LessEqualThanOP<Scalar>>>
operator <= (const ExprOP<Scalar, T>& left, const tml::Matrix<Scalar>& right)
{
	TML_ASSERT_SHAPE(left, right);
	typedef BinaryOP<Scalar, ExprOP<Scalar, T>, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
	return ExprOP<Scalar, ExprType>(ExprType(left, right.cbegin()), left.shape);
}

template<typename Scalar, typename Left, typename Right>
ExprOP<Scalar, BinaryOP<Scalar, ExprOP<Scalar, Left>, ExprOP<Scalar, Right>, tml::lazy::LessEqualThanOP<Scalar>>>
operator <= (const ExprOP<Scalar, Left>& left, const ExprOP<Scalar, Right>& right)
{
	TML_ASSERT_SHAPE(left, right);
	typedef BinaryOP<Scalar, ExprOP<Scalar, Left>, ExprOP<Scalar, Right>, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
	return ExprOP<Scalar, ExprType>(ExprType(left, right), left.shape);
}

template<typename Scalar>
ExprOP<Scalar, BinaryOP<Scalar, ScalarExpr<Scalar>, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::LessEqualThanOP<Scalar>>>
operator <=(Scalar left, const tml::Matrix<Scalar>& right)
{
	typedef BinaryOP<Scalar, ScalarExpr<Scalar>, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
	return ExprOP<Scalar, ExprType>(ExprType(left, right.cbegin()), right.GetShape());
}

template<typename Scalar>
ExprOP<Scalar, BinaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, ScalarExpr<Scalar>, tml::lazy::LessEqualThanOP<Scalar>>>
operator <=(const tml::Matrix<Scalar>& left, Scalar right)
{
	typedef BinaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, ScalarExpr<Scalar>, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
	return ExprOP<Scalar, ExprType>(ExprType(left.cbegin(), right), left.GetShape());
}

template<typename Scalar, typename T>
ExprOP<Scalar, BinaryOP<Scalar, ExprOP<Scalar, T>, ScalarExpr<Scalar>, tml::lazy::LessEqualThanOP<Scalar>>>
operator <=(const ExprOP<Scalar, T>& left, Scalar right)
{
	typedef BinaryOP<Scalar, ExprOP<Scalar, T>, ScalarExpr<Scalar>, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
	return ExprOP<Scalar, ExprType>(ExprType(left, right), left.shape);
}

template<typename Scalar, typename T>
ExprOP<Scalar, BinaryOP<Scalar, ScalarExpr<Scalar>, ExprOP<Scalar, T>, tml::lazy::LessEqualThanOP<Scalar>>>
operator <=(Scalar left, const ExprOP<Scalar, T>& right)
{
	typedef BinaryOP<Scalar, ScalarExpr<Scalar>, ExprOP<Scalar, T>, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
	return ExprOP<Scalar, ExprType>(ExprType(left, right), right.shape);
}

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		Scalar LessEqualThan(Scalar left, Scalar right)
		{
			return LessEqualThanOP<Scalar>::op(left, right);
		}

		template<typename Scalar>
		ExprOP<Scalar, BinaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::LessEqualThanOP<Scalar>>>
			LessEqualThan(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef BinaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left.cbegin(), right.cbegin()), left.GetShape());
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, BinaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, ExprOP<Scalar, T>, tml::lazy::LessEqualThanOP<Scalar>>>
			LessEqualThan(const tml::Matrix<Scalar>& left, const ExprOP<Scalar, T>& right)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef BinaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, ExprOP<Scalar, T>, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left.cbegin(), right), right.shape);
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, BinaryOP<Scalar, ExprOP<Scalar, T>, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::LessEqualThanOP<Scalar>>>
			LessEqualThan(const ExprOP<Scalar, T>& left, const tml::Matrix<Scalar>& right)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef BinaryOP<Scalar, ExprOP<Scalar, T>, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left, right.cbegin()), left.shape);
		}

		template<typename Scalar, typename Left, typename Right>
		ExprOP<Scalar, BinaryOP<Scalar, ExprOP<Scalar, Left>, ExprOP<Scalar, Right>, tml::lazy::LessEqualThanOP<Scalar>>>
			LessEqualThan(const ExprOP<Scalar, Left>& left, const ExprOP<Scalar, Right>& right)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef BinaryOP<Scalar, ExprOP<Scalar, Left>, ExprOP<Scalar, Right>, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left, right), left.shape);
		}

		template<typename Scalar>
		ExprOP<Scalar, BinaryOP<Scalar, ScalarExpr<Scalar>, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::LessEqualThanOP<Scalar>>>
			LessEqualThan(Scalar left, const tml::Matrix<Scalar>& right)
		{
			typedef BinaryOP<Scalar, ScalarExpr<Scalar>, typename tml::Matrix<Scalar>::const_iterator, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left, right.cbegin()), right.GetShape());
		}

		template<typename Scalar>
		ExprOP<Scalar, BinaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, ScalarExpr<Scalar>, tml::lazy::LessEqualThanOP<Scalar>>>
			LessEqualThan(const tml::Matrix<Scalar>& left, Scalar right)
		{
			typedef BinaryOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, ScalarExpr<Scalar>, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left.cbegin(), right), left.GetShape());
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, BinaryOP<Scalar, ExprOP<Scalar, T>, ScalarExpr<Scalar>, tml::lazy::LessEqualThanOP<Scalar>>>
			LessEqualThan(const ExprOP<Scalar, T>& left, Scalar right)
		{
			typedef BinaryOP<Scalar, ExprOP<Scalar, T>, ScalarExpr<Scalar>, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left, right), left.shape);
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, BinaryOP<Scalar, ScalarExpr<Scalar>, ExprOP<Scalar, T>, tml::lazy::LessEqualThanOP<Scalar>>>
			LessEqualThan(Scalar left, const ExprOP<Scalar, T>& right)
		{
			typedef BinaryOP<Scalar, ScalarExpr<Scalar>, ExprOP<Scalar, T>, tml::lazy::LessEqualThanOP<Scalar>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left, right), right.shape);
		}
	}
}