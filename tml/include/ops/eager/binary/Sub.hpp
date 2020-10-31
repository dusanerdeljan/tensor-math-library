#pragma once

#include "../../Assert.hpp"
#include "../ExecutionPolicy.hpp"
#include "../../lazy/Expr.hpp"
#include "../serial/SerialBinaryOP.hpp"
#include "../parallel/ParallelBinaryOP.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> sub(const tml::matrix<Scalar>& left, const tml::matrix<Scalar>& right, Backend = tml::execution::seq)
		{
			TML_ASSERT_SHAPE(left, right);
			tml::matrix<Scalar> result(left.get_shape());
			details::backend::binary_op_backend<Scalar, Backend>::do_op(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x - y); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> sub(const tml::matrix<Scalar>& left, const expr_op<Scalar, T>& rightExpr, Backend = tml::execution::seq)
		{
			TML_ASSERT_SHAPE(left, rightExpr);
			tml::matrix<Scalar> result(rightExpr.shape);
			tml::matrix<Scalar> right = rightExpr;
			details::backend::binary_op_backend<Scalar, Backend>::do_op(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x - y); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> sub(const expr_op<Scalar, T>& leftExpr, const tml::matrix<Scalar>& right, Backend = tml::execution::seq)
		{
			TML_ASSERT_SHAPE(leftExpr, right);
			tml::matrix<Scalar> result(leftExpr.shape);
			tml::matrix<Scalar> left = leftExpr;
			details::backend::binary_op_backend<Scalar, Backend>::do_op(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x - y); });
			return result;
		}

		template<typename Scalar, typename Left, typename Right, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> sub(const expr_op<Scalar, Left>& leftExpr, const expr_op<Scalar, Right>& rightExpr, Backend = tml::execution::seq)
		{
			TML_ASSERT_SHAPE(leftExpr, rightExpr);
			tml::matrix<Scalar> left = leftExpr;
			tml::matrix<Scalar> right = rightExpr;
			tml::matrix<Scalar> result(leftExpr.shape);
			details::backend::binary_op_backend<Scalar, Backend>::do_op(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x - y); });
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> sub(const tml::matrix<Scalar>& left, Scalar right, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(left.get_shape());
			details::backend::binary_op_backend<Scalar, Backend>::do_op(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x - y); });
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> sub(Scalar left, const tml::matrix<Scalar>& right, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(right.get_shape());
			details::backend::binary_op_backend<Scalar, Backend>::do_op(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x - y); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> sub(const expr_op<Scalar, T>& leftExpr, Scalar right, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> left = leftExpr;
			tml::matrix<Scalar> result(leftExpr.shape);
			details::backend::binary_op_backend<Scalar, Backend>::do_op(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x - y); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::matrix<Scalar> sub(Scalar left, const expr_op<Scalar, T>& rightExpr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> right = rightExpr;
			tml::matrix<Scalar> result(rightExpr.shape);
			details::backend::binary_op_backend<Scalar, Backend>::do_op(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x - y); });
			return result;
		}
	}
}
