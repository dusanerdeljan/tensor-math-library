#pragma once

#include "../../lazy/Expr.hpp"
#include "../ExecutionPolicy.hpp"
#include "../serial/SerialArgmax.hpp"
#include "../parallel/ParallelArgmax.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar>
		Scalar Argmax(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			Scalar result;
			if (execPolicy == tml::SERIAL)
				details::SerialArgmaxAll(matrix, result);
			else
				details::ParallelArgmaxAll(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		Scalar Argmax(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			const tml::Matrix<Scalar> matrix = expr;
			Scalar result;
			if (execPolicy == tml::SERIAL)
				details::SerialArgmaxAll(matrix, result);
			else
				details::ParallelArgmaxAll(matrix, result);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> ArgmaxRows(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Rows() });
			if (execPolicy == tml::SERIAL)
				details::SerialArgmaxRows(matrix, result);
			else
				details::ParallelArgmaxRows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> ArgmaxRows(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Rows });
			const tml::Matrix<Scalar> matrix = expr;
			if (execPolicy == tml::SERIAL)
				details::SerialArgmaxRows(matrix, result);
			else
				details::ParallelArgmaxRows(matrix, result);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> ArgmaxColumns(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Columns() });
			if (execPolicy == tml::SERIAL)
				details::SerialArgmaxColumns(matrix, result);
			else
				details::ParallelArgmaxColumns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> ArgmaxColumns(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Columns });
			const tml::Matrix<Scalar> matrix = expr;
			if (execPolicy == tml::SERIAL)
				details::SerialArgmaxColumns(matrix, result);
			else
				details::ParallelArgmaxColumns(matrix, result);
			return result;
		}
	}
}