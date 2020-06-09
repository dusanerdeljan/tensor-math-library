#pragma once

#include "../lazy/Expr.hpp"
#include "ExecutionPolicy.hpp"
#include "serial/SerialMax.hpp"
#include "parallel/ParallelMax.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar>
		Scalar Max(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			Scalar result;
			if (execPolicy == tml::SERIAL)
				details::SerialMaxAll(matrix, result);
			else
				details::ParallelMaxAll(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		Scalar Max(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			const tml::Matrix<Scalar> matrix = expr;
			Scalar result;
			if (execPolicy == tml::SERIAL)
				details::SerialMaxAll(matrix, result);
			else
				details::ParallelMaxAll(matrix, result);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> MaxRows(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Rows() });
			if (execPolicy == tml::SERIAL)
				details::SerialMaxRows(matrix, result);
			else
				details::ParallelMaxRows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> MaxRows(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Rows });
			const tml::Matrix<Scalar> matrix = expr;
			if (execPolicy == tml::SERIAL)
				details::SerialMaxRows(matrix, result);
			else
				details::ParallelMaxRows(matrix, result);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> MaxColumns(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Columns() });
			if (execPolicy == tml::SERIAL)
				details::SerialMaxColumns(matrix, result);
			else
				details::ParallelMaxColumns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> MaxColumns(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Columns });
			const tml::Matrix<Scalar> matrix = expr;
			if (execPolicy == tml::SERIAL)
				details::SerialMaxColumns(matrix, result);
			else
				details::ParallelMaxColumns(matrix, result);
			return result;
		}
	}
}