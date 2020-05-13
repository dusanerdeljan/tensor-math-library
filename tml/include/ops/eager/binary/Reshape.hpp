#pragma once

#include "..\..\lazy\Expr.hpp"
#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar>
		tml::Matrix<Scalar> Reshape(const tml::Matrix<Scalar>& matrix, const Shape& newShape)
		{
			tml::Matrix<Scalar> result = matrix;
			result.SetShape(newShape);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Reshape(const ExprOP<Scalar, T>& expr, const Shape& newShape)
		{
			tml::Matrix<Scalar> result = expr;
			result.SetShape(newShape);
			return std::move(result);
		}
	}
}
