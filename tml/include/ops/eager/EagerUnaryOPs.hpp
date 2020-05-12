#pragma once

#include "serial\SerialUnaryOP.hpp"
#include "parallel\ParallelUnaryOP.hpp"
#include "..\lazy\Expr.hpp"

namespace tml
{
	namespace eager
	{
		// TODO: Make template specialization for each execution policy
		template<typename Scalar, typename OP>
		tml::Matrix<Scalar> CustomUnaryOP(const tml::Matrix<Scalar>& matrix, OP&& op, tml::ExecutionPolicy execPolicy=tml::SERIAL, tml::ParallelismPolicy parallelism=tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				CustomSerialUnaryOP(matrix, result, std::move(op));
			return std::move(result);
		}

		template<typename Scalar, typename T, typename OP>
		tml::Matrix<Scalar> CustomUnaryOP(const ExprOP<Scalar, T>& expr, OP&& op, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				CustomSerialUnaryOP(matrix, result, std::move(op));
			return std::move(result);
		}
	}
}