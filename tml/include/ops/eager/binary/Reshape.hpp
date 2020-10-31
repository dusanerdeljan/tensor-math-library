#pragma once

#include "../../Assert.hpp"
#include "../../lazy/Expr.hpp"
#include "../../../matrix/Matrix.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar>
		TML_INLINE tml::matrix<Scalar> reshape(const tml::matrix<Scalar>& matrix, const shape& newShape)
		{
			TML_ASSERT_RESHAPE(matrix, newShape);
			tml::matrix<Scalar> result = matrix;
			result.set_shape(newShape);
			return result;
		}

		template<typename Scalar, typename T>
		TML_INLINE tml::matrix<Scalar> reshape(const expr_op<Scalar, T>& expr, const shape& newShape)
		{
			TML_ASSERT_RESHAPE(expr, newShape);
			tml::matrix<Scalar> result = expr;
			result.set_shape(newShape);
			return result;
		}
	}
}
