#pragma once

#include "../Assert.hpp"
#include "../lazy/Expr.hpp"
#include "ExecutionPolicy.hpp"
#include "serial/SerialMatrixMultiplication.hpp"
#include "parallel/ParallelMatrixMultiplication.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Matmul(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, Backend backend = tml::execution::seq)
		{
			TML_ASSERT_MATMUL(left, right);
			tml::Matrix<Scalar> result = tml::Matrix<Scalar>::Zeros({ left.Rows(), right.Columns() });
			details::backend::MatmulBackend<Scalar, Backend>::DoOP(left, right, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Matmul(const tml::Matrix<Scalar>& left, const ExprOP<Scalar, T>& rightExpr, Backend backend = tml::execution::seq)
		{
			TML_ASSERT_MATMUL(left, rightExpr);
			tml::Matrix<Scalar> result = tml::Matrix<Scalar>::Zeros({ left.Rows(), rightExpr.shape.Columns });
			const tml::Matrix<Scalar> right = rightExpr;
			details::backend::MatmulBackend<Scalar, Backend>::DoOP(left, right, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Matmul(const ExprOP<Scalar, T>& leftExpr, const tml::Matrix<Scalar>& right, Backend backend = tml::execution::seq)
		{
			TML_ASSERT_MATMUL(leftExpr, right);
			tml::Matrix<Scalar> result = tml::Matrix<Scalar>::Zeros({ leftExpr.shape.Rows, right.Columns() });
			const tml::Matrix<Scalar> left = leftExpr;
			details::backend::MatmulBackend<Scalar, Backend>::DoOP(left, right, result);
			return result;
		}

		template<typename Scalar, typename Left, typename Right, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Matmul(const ExprOP<Scalar, Left>& leftExpr, const ExprOP<Scalar, Right>& rightExpr, Backend backend = tml::execution::seq)
		{
			TML_ASSERT_MATMUL(leftExpr, rightExpr);
			tml::Matrix<Scalar> result = tml::Matrix<Scalar>::Zeros({ leftExpr.shape.Rows, rightExpr.shape.Columns });
			const tml::Matrix<Scalar> left = leftExpr;
			const tml::Matrix<Scalar> right = rightExpr;
			details::backend::MatmulBackend<Scalar, Backend>::DoOP(left, right, result);
			return result;
		}
	}
}
