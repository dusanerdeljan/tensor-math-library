#pragma once

#include "..\ExecutionPolicy.hpp"
#include "..\..\lazy\Expr.hpp"
#include "..\serial\SerialBinaryOP.hpp"
#include "..\parallel\ParallelBinaryOP.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar>
		tml::Matrix<Scalar> Maximum(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(left.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialMaximum(left, right, result);
			else
				details::ParallelMaximum(left, right, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Maximum(const tml::Matrix<Scalar>& left, const ExprOP<Scalar, T>& rightExpr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(rightExpr.shape);
			tml::Matrix<Scalar> right = rightExpr;
			if (execPolicy == tml::SERIAL)
				details::SerialMaximum(left, right, result);
			else
				details::ParallelMaximum(left, right, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Maximum(const ExprOP<Scalar, T>& leftExpr, const tml::Matrix<Scalar>& right, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(leftExpr.shape);
			tml::Matrix<Scalar> left = leftExpr;
			if (execPolicy == tml::SERIAL)
				details::SerialMaximum(left, right, result);
			else
				details::ParallelMaximum(left, right, result, parallelism);
			return result;
		}

		template<typename Scalar, typename Left, typename Right>
		tml::Matrix<Scalar> Maximum(const ExprOP<Scalar, Left>& leftExpr, const ExprOP<Scalar, Right>& rightExpr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> left = leftExpr;
			tml::Matrix<Scalar> right = rightExpr;
			tml::Matrix<Scalar> result(leftExpr.shape);
			if (execPolicy == tml::SERIAL)
				details::SerialMaximum(left, right, result);
			else
				details::ParallelMaximum(left, right, result, parallelism);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> Maximum(const tml::Matrix<Scalar>& left, Scalar right, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(left.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialMaximum(left, right, result);
			else
				details::ParallelMaximum(left, right, result, parallelism);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> Maximum(Scalar left, const tml::Matrix<Scalar>& right, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(right.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialMaximum(left, right, result);
			else
				details::ParallelMaximum(left, right, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Maximum(const ExprOP<Scalar, T>& leftExpr, Scalar right, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> left = leftExpr;
			tml::Matrix<Scalar> result(leftExpr.shape);
			if (execPolicy == tml::SERIAL)
				details::SerialMaximum(left, right, result);
			else
				details::ParallelMaximum(left, right, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Maximum(Scalar left, const ExprOP<Scalar, T>& rightExpr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> right = rightExpr;
			tml::Matrix<Scalar> result(rightExpr.shape);
			if (execPolicy == tml::SERIAL)
				details::SerialMaximum(left, right, result);
			else
				details::ParallelMaximum(left, right, result, parallelism);
			return result;
		}
	}
}
