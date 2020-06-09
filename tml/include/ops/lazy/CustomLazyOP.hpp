#pragma once

#include "Expr.hpp"
#include "../Assert.hpp"
#include "../../matrix/Matrix.hpp"

template<typename Scalar, typename Operand, typename OP>
struct CustomUnaryLazyExprOP
{
	Operand operand;
	OP op;
	CustomUnaryLazyExprOP(const Operand& operand, OP&& op) : operand(operand), op(std::move(op)) {}
	void operator++() { ++operand; }
	Scalar operator*() const
	{
		return op(*operand);
	}
};

template<typename Scalar, typename Left, typename Right, typename OP>
struct CustomBinaryLazyExprOP
{
	Left left;
	Right right;
	OP op;
	CustomBinaryLazyExprOP(const Left& left, const Right& right, OP&& op) : left(left), right(right), op(std::move(op)) {}
	void operator++() { ++left; ++right; }
	Scalar operator*() const
	{
		return op(*left, *right);
	}
};

namespace tml
{
	namespace lazy
	{
		template<typename Scalar, typename OP>
		Scalar CustomOP(Scalar value, OP&& op)
		{
			return op(value);
		}

		template<typename Scalar, typename OP>
		ExprOP<Scalar, CustomUnaryLazyExprOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, OP>>
			CustomOP(const tml::Matrix<Scalar>& matrix, OP&& op)
		{
			typedef CustomUnaryLazyExprOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, OP> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix.cbegin(), std::move(op)), matrix.GetShape());
		}

		template<typename Scalar, typename T, typename OP>
		ExprOP<Scalar, CustomUnaryLazyExprOP<Scalar, ExprOP<Scalar, T>, OP>>
			CustomOP(const ExprOP<Scalar, T>& expr, OP&& op)
		{
			typedef CustomUnaryLazyExprOP<Scalar, ExprOP<Scalar, T>, OP> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr, std::move(op)), expr.shape);
		}

		template<typename Scalar, typename OP>
		ExprOP<Scalar, CustomBinaryLazyExprOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::const_iterator, OP>>
			CustomOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, OP&& op)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef CustomBinaryLazyExprOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::const_iterator, OP> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left.cbegin(), right.cbegin(), std::move(op)), left.GetShape());
		}

		template<typename Scalar, typename T, typename OP>
		ExprOP<Scalar, CustomBinaryLazyExprOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, ExprOP<Scalar, T>, OP>>
			CustomOP(const tml::Matrix<Scalar>& left, const ExprOP<Scalar, T>& right, OP&& op)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef CustomBinaryLazyExprOP<Scalar, typename tml::Matrix<Scalar>::const_iterator, ExprOP<Scalar, T>, OP> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left.cbegin(), right, std::move(op)), right.shape);
		}

		template<typename Scalar, typename T, typename OP>
		ExprOP<Scalar, CustomBinaryLazyExprOP<Scalar, ExprOP<Scalar, T>, typename tml::Matrix<Scalar>::const_iterator, OP>>
			CustomOP(const ExprOP<Scalar, T>& left, const tml::Matrix<Scalar>& right, OP&& op)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef CustomBinaryLazyExprOP<Scalar, ExprOP<Scalar, T>, typename tml::Matrix<Scalar>::const_iterator, OP> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left, right.cbegin(), std::move(op)), left.shape);
		}

		template<typename Scalar, typename Left, typename Right, typename OP>
		ExprOP<Scalar, CustomBinaryLazyExprOP<Scalar, ExprOP<Scalar, Left>, ExprOP<Scalar, Right>, OP>>
			CustomOP(const ExprOP<Scalar, Left>& left, const ExprOP<Scalar, Right>& right, OP&& op)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef CustomBinaryLazyExprOP<Scalar, ExprOP<Scalar, Left>, ExprOP<Scalar, Right>, OP> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(left, right, std::move(op)), left.shape);
		}
	}
}
