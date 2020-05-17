#pragma once

#include "..\lazy\Expr.hpp"
#include "serial\SerialMean.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar>
		Scalar Mean(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			Scalar result;
			if (execPolicy == tml::SERIAL)
				details::SerialMeanAll(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		Scalar Mean(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			const tml::Matrix<Scalar>& matrix = expr;
			Scalar result;
			if (execPolicy == tml::SERIAL)
				details::SerialMeanAll(matrix, result);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> MeanRows(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Rows() });
			if (execPolicy == tml::SERIAL)
				details::SerialMeanRows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> MeanRows(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Rows });
			const tml::Matrix<Scalar> matrix = expr;
			if (execPolicy == tml::SERIAL)
				details::SerialMeanRows(matrix, result);
			return result;
		}

		template<typename Scalar>
		tml::Matrix<Scalar> MeanColumns(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Columns() });
			if (execPolicy == tml::SERIAL)
				details::SerialMeanColumns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> MeanColumns(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Columns });
			const tml::Matrix<Scalar> matrix = expr;
			if (execPolicy == tml::SERIAL)
				details::SerialMeanColumns(matrix, result);
			return result;
		}
	}
}