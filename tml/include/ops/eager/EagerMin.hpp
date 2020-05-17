#pragma once

#include "..\lazy\Expr.hpp"
#include "ExecutionPolicy.hpp"
#include "serial\SerialMin.hpp"
#include "parallel\ParallelMin.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar>
		Scalar Min(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			Scalar result;
			if (execPolicy == tml::SERIAL)
				details::SerialMinAll(matrix, result);
			else
				details::ParallelMinAll(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		Scalar Min(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			const tml::Matrix<Scalar>& matrix = expr;
			Scalar result;
			if (execPolicy == tml::SERIAL)
				details::SerialMinAll(matrix, result);
			else
				details::ParallelMinAll(matrix, result);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> MinRows(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Rows() });
			if (execPolicy == tml::SERIAL)
				details::SerialMinRows(matrix, result);
			else
				details::ParallelMinRows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> MinRows(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Rows });
			const tml::Matrix<Scalar> matrix = expr;
			if (execPolicy == tml::SERIAL)
				details::SerialMinRows(matrix, result);
			else
				details::ParallelMinRows(matrix, result);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> MinColumns(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Columns() });
			if (execPolicy == tml::SERIAL)
				details::SerialMinColumns(matrix, result);
			else
				details::ParallelMinColumns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> MinColumns(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Columns });
			const tml::Matrix<Scalar> matrix = expr;
			if (execPolicy == tml::SERIAL)
				details::SerialMinColumns(matrix, result);
			else
				details::ParallelMinColumns(matrix, result);
			return result;
		}
	}
}