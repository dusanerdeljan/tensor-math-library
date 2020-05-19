#pragma once

#include "..\lazy\Expr.hpp"
#include "ExecutionPolicy.hpp"
#include "serial\SerialArgmin.hpp"
#include "parallel\ParallelArgmin.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar>
		Scalar Argmin(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			Scalar result;
			if (execPolicy == tml::SERIAL)
				details::SerialArgminAll(matrix, result);
			else
				details::ParallelArgminAll(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		Scalar Argmin(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			const tml::Matrix<Scalar> matrix = expr;
			Scalar result;
			if (execPolicy == tml::SERIAL)
				details::SerialArgminAll(matrix, result);
			else
				details::ParallelArgminAll(matrix, result);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> ArgminRows(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Rows() });
			if (execPolicy == tml::SERIAL)
				details::SerialArgminRows(matrix, result);
			else
				details::ParallelArgminRows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> ArgminRows(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Rows });
			const tml::Matrix<Scalar> matrix = expr;
			if (execPolicy == tml::SERIAL)
				details::SerialArgminRows(matrix, result);
			else
				details::ParallelArgminRows(matrix, result);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> ArgminColumns(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Columns() });
			if (execPolicy == tml::SERIAL)
				details::SerialArgminColumns(matrix, result);
			else
				details::ParallelArgminColumns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> ArgminColumns(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Columns });
			const tml::Matrix<Scalar> matrix = expr;
			if (execPolicy == tml::SERIAL)
				details::SerialArgminColumns(matrix, result);
			else
				details::ParallelArgminColumns(matrix, result);
			return result;
		}
	}
}