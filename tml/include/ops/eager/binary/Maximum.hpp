#pragma once

#include "..\..\Assert.hpp"
#include "..\ExecutionPolicy.hpp"
#include "..\..\lazy\Expr.hpp"
#include "..\serial\SerialBinaryOP.hpp"
#include "..\parallel\ParallelBinaryOP.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Maximum(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, Backend backend = tml::execution::seq)
		{
			TML_ASSERT_SHAPE(left, right);
			tml::Matrix<Scalar> result(left.GetShape());
			details::backend::BinaryOPBackend<Scalar, Backend>::DoOP(left, right, result, [](Scalar x, Scalar y) { return std::max<Scalar>(x, y); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Maximum(const tml::Matrix<Scalar>& left, const ExprOP<Scalar, T>& rightExpr, Backend backend = tml::execution::seq)
		{
			TML_ASSERT_SHAPE(left, rightExpr);
			tml::Matrix<Scalar> result(rightExpr.shape);
			tml::Matrix<Scalar> right = rightExpr;
			details::backend::BinaryOPBackend<Scalar, Backend>::DoOP(left, right, result, [](Scalar x, Scalar y) { return std::max<Scalar>(x, y); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Maximum(const ExprOP<Scalar, T>& leftExpr, const tml::Matrix<Scalar>& right, Backend backend = tml::execution::seq)
		{
			TML_ASSERT_SHAPE(leftExpr, right);
			tml::Matrix<Scalar> result(leftExpr.shape);
			tml::Matrix<Scalar> left = leftExpr;
			details::backend::BinaryOPBackend<Scalar, Backend>::DoOP(left, right, result, [](Scalar x, Scalar y) { return std::max<Scalar>(x, y); });
			return result;
		}

		template<typename Scalar, typename Left, typename Right, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Maximum(const ExprOP<Scalar, Left>& leftExpr, const ExprOP<Scalar, Right>& rightExpr, Backend backend = tml::execution::seq)
		{
			TML_ASSERT_SHAPE(leftExpr, rightExpr);
			tml::Matrix<Scalar> left = leftExpr;
			tml::Matrix<Scalar> right = rightExpr;
			tml::Matrix<Scalar> result(leftExpr.shape);
			details::backend::BinaryOPBackend<Scalar, Backend>::DoOP(left, right, result, [](Scalar x, Scalar y) { return std::max<Scalar>(x, y); });
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Maximum(const tml::Matrix<Scalar>& left, Scalar right, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(left.GetShape());
			details::backend::BinaryOPBackend<Scalar, Backend>::DoOP(left, right, result, [](Scalar x, Scalar y) { return std::max<Scalar>(x, y); });
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Maximum(Scalar left, const tml::Matrix<Scalar>& right, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(right.GetShape());
			details::backend::BinaryOPBackend<Scalar, Backend>::DoOP(left, right, result, [](Scalar x, Scalar y) { return std::max<Scalar>(x, y); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Maximum(const ExprOP<Scalar, T>& leftExpr, Scalar right, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> left = leftExpr;
			tml::Matrix<Scalar> result(leftExpr.shape);
			details::backend::BinaryOPBackend<Scalar, Backend>::DoOP(left, right, result, [](Scalar x, Scalar y) { return std::max<Scalar>(x, y); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Maximum(Scalar left, const ExprOP<Scalar, T>& rightExpr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> right = rightExpr;
			tml::Matrix<Scalar> result(rightExpr.shape);
			details::backend::BinaryOPBackend<Scalar, Backend>::DoOP(left, right, result, [](Scalar x, Scalar y) { return std::max<Scalar>(x, y); });
			return result;
		}
	}
}
