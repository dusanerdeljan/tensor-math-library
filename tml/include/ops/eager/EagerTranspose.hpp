#pragma once

#include "ExecutionPolicy.hpp"
#include "serial\SerialTranspose.hpp"
#include "parallel\ParallelTranspose.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar>
		tml::Matrix<Scalar> Transpose(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy=tml::SERIAL)
		{
			tml::Matrix<Scalar> result(tml::Shape{ matrix.Columns(), matrix.Rows() });
			if (execPolicy == tml::SERIAL)
				SerialTranspose(matrix, result);
			else
				ParallelTranspose(matrix, result);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Transpose(const ExprOP<Scalar, T> expr, tml::ExecutionPolicy execPolicy = tml::SERIAL)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(tml::Shape{ matrix.Columns(), matrix.Rows() });
			if (execPolicy == tml::SERIAL)
				SerialTranspose(matrix, result);
			else
				ParallelTranspose(matrix, result);
			return result;
		}
	}
}