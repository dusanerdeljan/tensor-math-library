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
		TML_INLINE tml::matrix<Scalar> matmul(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right, Backend = tml::execution::seq)
		{
			TML_ASSERT_MATMUL(left, right);
			tml::matrix<Scalar> result = tml::matrix<Scalar>::zeros({ left.rows(), right.columns() });
			details::backend::matmul_backend<Scalar, Backend>::do_op(left, right, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> matmul(const tml::matrix<Scalar>& left, const expr_op<Scalar, T>& rightExpr, Backend = tml::execution::seq)
		{
			TML_ASSERT_MATMUL(left, rightExpr);
			tml::matrix<Scalar> result = tml::matrix<Scalar>::zeros({ left.rows(), rightExpr.shape.columns });
			const tml::matrix<Scalar> right = rightExpr;
			details::backend::matmul_backend<Scalar, Backend>::do_op(left, right, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> matmul(const expr_op<Scalar, T>& leftExpr, const tml::matrix<Scalar>& right, Backend = tml::execution::seq)
		{
			TML_ASSERT_MATMUL(leftExpr, right);
			tml::matrix<Scalar> result = tml::matrix<Scalar>::zeros({ leftExpr.shape.rows, right.columns() });
			const tml::matrix<Scalar> left = leftExpr;
			details::backend::matmul_backend<Scalar, Backend>::do_op(left, right, result);
			return result;
		}

		template<typename Scalar, typename Left, typename Right, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> matmul(const expr_op<Scalar, Left>& leftExpr, const expr_op<Scalar, Right>& rightExpr, Backend = tml::execution::seq)
		{
			TML_ASSERT_MATMUL(leftExpr, rightExpr);
			tml::matrix<Scalar> result = tml::matrix<Scalar>::zeros({ leftExpr.shape.rows, rightExpr.shape.columns });
			const tml::matrix<Scalar> left = leftExpr;
			const tml::matrix<Scalar> right = rightExpr;
			details::backend::matmul_backend<Scalar, Backend>::do_op(left, right, result);
			return result;
		}
	}
}
