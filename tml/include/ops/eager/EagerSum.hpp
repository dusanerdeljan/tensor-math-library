#pragma once

#include "..\lazy\Expr.hpp"
#include "serial\SerialSum.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar>
		Scalar Sum(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			Scalar result;
			if (execPolicy == tml::SERIAL)
				details::SerialSumAll(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		Scalar Sum(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			const tml::Matrix<Scalar>& matrix = expr;
			Scalar result;
			if (execPolicy == tml::SERIAL)
				details::SerialSumAll(matrix, result);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> SumRows(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Rows() });
			if (execPolicy == tml::SERIAL)
				details::SerialSumRows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> SumRows(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Rows});
			const tml::Matrix<Scalar> matrix = expr;
			if (execPolicy == tml::SERIAL)
				details::SerialSumRows(matrix, result);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> SumColumns(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Columns() });
			if (execPolicy == tml::SERIAL)
				details::SerialSumColumns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> SumColumns(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Columns });
			const tml::Matrix<Scalar> matrix = expr;
			if (execPolicy == tml::SERIAL)
				details::SerialSumColumns(matrix, result);
			return result;
		}
	}
}