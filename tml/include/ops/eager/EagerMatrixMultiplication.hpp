#pragma once

#include "..\Assert.hpp"
#include "..\lazy\Expr.hpp"
#include "ExecutionPolicy.hpp"
#include "serial\SerialMatrixMultiplication.hpp"
#include "parallel\ParallelMatrixMultiplication.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar>
		tml::Matrix<Scalar> Matmul(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			TML_ASSERT_MATMUL(left, right);
			tml::Matrix<Scalar> result = tml::Matrix<Scalar>::Zeros({ left.Rows(), right.Columns() });
			if (execPolicy == tml::SERIAL)
				details::SerialMatmul(left, right, result);
			else
				details::ParallelMatmul(left, right, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Matmul(const tml::Matrix<Scalar>& left, const ExprOP<Scalar, T>& rightExpr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			TML_ASSERT_MATMUL(left, rightExpr);
			tml::Matrix<Scalar> result = tml::Matrix<Scalar>::Zeros({ left.Rows(), rightExpr.shape.Columns });
			const tml::Matrix<Scalar> right = rightExpr;
			if (execPolicy == tml::SERIAL)
				details::SerialMatmul(left, right, result);
			else
				details::ParallelMatmul(left, right, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Matmul(const ExprOP<Scalar, T>& leftExpr, const tml::Matrix<Scalar>& right, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			TML_ASSERT_MATMUL(leftExpr, right);
			tml::Matrix<Scalar> result = tml::Matrix<Scalar>::Zeros({ leftExpr.shape.Rows, right.Columns() });
			const tml::Matrix<Scalar> left = leftExpr;
			if (execPolicy == tml::SERIAL)
				details::SerialMatmul(left, right, result);
			else
				details::ParallelMatmul(left, right, result);
			return result;
		}

		template<typename Scalar, typename Left, typename Right>
		tml::Matrix<Scalar> Matmul(const ExprOP<Scalar, Left>& leftExpr, const ExprOP<Scalar, Right>& rightExpr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			TML_ASSERT_MATMUL(leftExpr, rightExpr);
			tml::Matrix<Scalar> result = tml::Matrix<Scalar>::Zeros({ leftExpr.shape.Rows, rightExpr.shape.Columns });
			const tml::Matrix<Scalar> left = leftExpr;
			const tml::Matrix<Scalar> right = rightExpr;
			if (execPolicy == tml::SERIAL)
				details::SerialMatmul(left, right, result);
			else
				details::ParallelMatmul(left, right, result);
			return result;
		}
	}
}
