#pragma once

#include "Expr.hpp"
#include "../Assert.hpp"
#include "../../matrix/Matrix.hpp"

template<typename Scalar, typename Operand, typename OP>
struct custom_unary_lazy_expr_op
{
	Operand operand;
	OP op;
	custom_unary_lazy_expr_op(const Operand& operand, OP&& op) : operand(operand), op(std::move(op)) {}
	void operator++() { ++operand; }
	Scalar operator*() const
	{
		return op(*operand);
	}
};

template<typename Scalar, typename Left, typename Right, typename OP>
struct custom_binary_lazy_expr_op
{
	Left left;
	Right right;
	OP op;
	custom_binary_lazy_expr_op(const Left& left, const Right& right, OP&& op) : left(left), right(right), op(std::move(op)) {}
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
		Scalar custom_op(Scalar value, OP&& op)
		{
			return op(value);
		}

		template<typename Scalar, typename OP>
		expr_op<Scalar, custom_unary_lazy_expr_op<Scalar, typename tml::matrix<Scalar>::const_iterator, OP>>
			custom_op(const tml::matrix<Scalar>& matrix, OP&& op)
		{
			typedef custom_unary_lazy_expr_op<Scalar, typename tml::matrix<Scalar>::const_iterator, OP> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(matrix.cbegin(), std::move(op)), matrix.get_shape());
		}

		template<typename Scalar, typename T, typename OP>
		expr_op<Scalar, custom_unary_lazy_expr_op<Scalar, expr_op<Scalar, T>, OP>>
			custom_op(const expr_op<Scalar, T>& expr, OP&& op)
		{
			typedef custom_unary_lazy_expr_op<Scalar, expr_op<Scalar, T>, OP> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(expr, std::move(op)), expr.shape);
		}

		template<typename Scalar, typename OP>
		expr_op<Scalar, custom_binary_lazy_expr_op<Scalar, typename tml::matrix<Scalar>::const_iterator, typename tml::matrix<Scalar>::const_iterator, OP>>
			custom_op(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right, OP&& op)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef custom_binary_lazy_expr_op<Scalar, typename tml::matrix<Scalar>::const_iterator, typename tml::matrix<Scalar>::const_iterator, OP> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left.cbegin(), right.cbegin(), std::move(op)), left.get_shape());
		}

		template<typename Scalar, typename T, typename OP>
		expr_op<Scalar, custom_binary_lazy_expr_op<Scalar, typename tml::matrix<Scalar>::const_iterator, expr_op<Scalar, T>, OP>>
			custom_op(const tml::matrix<Scalar>& left, const expr_op<Scalar, T>& right, OP&& op)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef custom_binary_lazy_expr_op<Scalar, typename tml::matrix<Scalar>::const_iterator, expr_op<Scalar, T>, OP> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left.cbegin(), right, std::move(op)), right.shape);
		}

		template<typename Scalar, typename T, typename OP>
		expr_op<Scalar, custom_binary_lazy_expr_op<Scalar, expr_op<Scalar, T>, typename tml::matrix<Scalar>::const_iterator, OP>>
			custom_op(const expr_op<Scalar, T>& left, const tml::matrix<Scalar>& right, OP&& op)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef custom_binary_lazy_expr_op<Scalar, expr_op<Scalar, T>, typename tml::matrix<Scalar>::const_iterator, OP> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left, right.cbegin(), std::move(op)), left.shape);
		}

		template<typename Scalar, typename Left, typename Right, typename OP>
		expr_op<Scalar, custom_binary_lazy_expr_op<Scalar, expr_op<Scalar, Left>, expr_op<Scalar, Right>, OP>>
			custom_op(const expr_op<Scalar, Left>& left, const expr_op<Scalar, Right>& right, OP&& op)
		{
			TML_ASSERT_SHAPE(left, right);
			typedef custom_binary_lazy_expr_op<Scalar, expr_op<Scalar, Left>, expr_op<Scalar, Right>, OP> ExprType;
			return expr_op<Scalar, ExprType>(ExprType(left, right, std::move(op)), left.shape);
		}
	}
}
