#pragma once

#include "../../Assert.hpp"
#include "../../lazy/Expr.hpp"
#include "../../../matrix/Matrix.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar>
		TML_INLINE tml::Matrix<Scalar> Reshape(const tml::Matrix<Scalar>& matrix, const Shape& newShape)
		{
			TML_ASSERT_RESHAPE(matrix, newShape);
			tml::Matrix<Scalar> result = matrix;
			result.SetShape(newShape);
			return result;
		}

		template<typename Scalar, typename T>
		TML_INLINE tml::Matrix<Scalar> Reshape(const ExprOP<Scalar, T>& expr, const Shape& newShape)
		{
			TML_ASSERT_RESHAPE(expr, newShape);
			tml::Matrix<Scalar> result = expr;
			result.SetShape(newShape);
			return result;
		}
	}
}
