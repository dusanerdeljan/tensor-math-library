#pragma once

#include "..\..\Assert.hpp"
#include "..\ExecutionPolicy.hpp"
#include "..\..\lazy\Expr.hpp"
#include "..\serial\SerialBinaryOP.hpp"
#include "..\parallel\ParallelBinaryOP.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename OP>
		tml::Matrix<Scalar> CustomBinaryOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, OP&&op, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			TML_ASSERT_SHAPE(left, right);
			tml::Matrix<Scalar> result(left.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCustomBinaryOP(left, right, result, std::move(op));
			else
				details::ParallelCustomBinaryOP(left, right, result, std::move(op), parallelism);
			return result;
		}

		template<typename Scalar, typename T, typename OP>
		tml::Matrix<Scalar> CustomBinaryOP(const tml::Matrix<Scalar>& left, const ExprOP<Scalar, T>& rightExpr, OP&&op, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			TML_ASSERT_SHAPE(left, rightExpr);
			tml::Matrix<Scalar> result(rightExpr.shape);
			tml::Matrix<Scalar> right = rightExpr;
			if (execPolicy == tml::SERIAL)
				details::SerialCustomBinaryOP(left, right, result, std::move(op));
			else
				details::ParallelCustomBinaryOP(left, right, result, std::move(op), parallelism);
			return result;
		}

		template<typename Scalar, typename T, typename OP>
		tml::Matrix<Scalar> CustomBinaryOP(const ExprOP<Scalar, T>& leftExpr, const tml::Matrix<Scalar>& right, OP&&op, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			TML_ASSERT_SHAPE(leftExpr, right);
			tml::Matrix<Scalar> result(leftExpr.shape);
			tml::Matrix<Scalar> left = leftExpr;
			if (execPolicy == tml::SERIAL)
				details::SerialCustomBinaryOP(left, right, result, std::move(op));
			else
				details::ParallelCustomBinaryOP(left, right, result, std::move(op), parallelism);
			return result;
		}

		template<typename Scalar, typename Left, typename Right, typename OP>
		tml::Matrix<Scalar> CustomBinaryOP(const ExprOP<Scalar, Left>& leftExpr, const ExprOP<Scalar, Right>& rightExpr, OP&&op, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			TML_ASSERT_SHAPE(leftExpr, rightExpr);
			tml::Matrix<Scalar> left = leftExpr;
			tml::Matrix<Scalar> right = rightExpr;
			tml::Matrix<Scalar> result(leftExpr.shape);
			if (execPolicy == tml::SERIAL)
				details::SerialCustomBinaryOP(left, right, result, std::move(op));
			else
				details::ParallelCustomBinaryOP(left, right, result, std::move(op), parallelism);
			return result;
		}

		template<typename Scalar, typename OP>
		tml::Matrix<Scalar> CustomBinaryOP(const tml::Matrix<Scalar>& left, Scalar right, OP&&op, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(left.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCustomBinaryOP(left, right, result, std::move(op));
			else
				details::ParallelCustomBinaryOP(left, right, result, std::move(op), parallelism);
			return result;
		}

		template<typename Scalar, typename OP>
		tml::Matrix<Scalar> CustomBinaryOP(Scalar left, const tml::Matrix<Scalar>& right, OP&&op, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(right.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCustomBinaryOP(left, right, result, std::move(op));
			else
				details::ParallelCustomBinaryOP(left, right, result, std::move(op), parallelism);
			return result;
		}

		template<typename Scalar, typename T, typename OP>
		tml::Matrix<Scalar> CustomBinaryOP(const ExprOP<Scalar, T>& leftExpr, Scalar right, OP&&op, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> left = leftExpr;
			tml::Matrix<Scalar> result(leftExpr.shape);
			if (execPolicy == tml::SERIAL)
				details::SerialCustomBinaryOP(left, right, result, std::move(op));
			else
				details::ParallelCustomBinaryOP(left, right, result, std::move(op), parallelism);
			return result;
		}

		template<typename Scalar, typename T, typename OP>
		tml::Matrix<Scalar> CustomBinaryOP(Scalar left, const ExprOP<Scalar, T>& rightExpr, OP&&op, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> right = rightExpr;
			tml::Matrix<Scalar> result(rightExpr.shape);
			if (execPolicy == tml::SERIAL)
				details::SerialCustomBinaryOP(left, right, result, std::move(op));
			else
				details::ParallelCustomBinaryOP(left, right, result, std::move(op), parallelism);
			return result;
		}
	}
}
