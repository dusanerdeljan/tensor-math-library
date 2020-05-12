#pragma once

#include "Expr.hpp"
#include "..\..\matrix\Matrix.hpp"

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
		Scalar CustomOP(Scalar left, Scalar right, OP&& op)
		{
			return op(left, right);
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
	}
}
