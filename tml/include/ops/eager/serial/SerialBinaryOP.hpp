#pragma once

#include <algorithm>
#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename OP>
		void SerialCustomBinaryOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), op);
		}

		template<typename Scalar>
		void SerialAdd(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return x + y; });
		}

		template<typename Scalar>
		void SerialAdd(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return x + right; });
		}

		template<typename Scalar>
		void SerialAdd(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return left + x; });
		}

		template<typename Scalar>
		void SerialMul(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return x * y; });
		}

		template<typename Scalar>
		void SerialMul(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return x * right; });
		}

		template<typename Scalar>
		void SerialMul(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return left * x; });
		}

		template<typename Scalar>
		void SerialSub(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return x - y; });
		}

		template<typename Scalar>
		void SerialSub(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return x - right; });
		}

		template<typename Scalar>
		void SerialSub(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return left - x; });
		}

		template<typename Scalar>
		void SerialDiv(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return x / y; });
		}

		template<typename Scalar>
		void SerialDiv(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return x / right; });
		}

		template<typename Scalar>
		void SerialDiv(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return left / x; });
		}

		template<typename Scalar>
		void SerialEqual(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return static_cast<Scalar>(x == y); });
		}

		template<typename Scalar>
		void SerialEqual(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return static_cast<Scalar>(x == right); });
		}

		template<typename Scalar>
		void SerialEqual(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return static_cast<Scalar>(left == x); });
		}

		template<typename Scalar>
		void SerialNotEqual(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return static_cast<Scalar>(x != y); });
		}

		template<typename Scalar>
		void SerialNotEqual(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return static_cast<Scalar>(x != right); });
		}

		template<typename Scalar>
		void SerialNotEqual(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return static_cast<Scalar>(left != x); });
		}

		template<typename Scalar>
		void SerialGreaterThan(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return static_cast<Scalar>(x > y); });
		}

		template<typename Scalar>
		void SerialGreaterThan(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return static_cast<Scalar>(x > right); });
		}

		template<typename Scalar>
		void SerialGreaterThan(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return static_cast<Scalar>(left > x); });
		}

		template<typename Scalar>
		void SerialLessThan(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return static_cast<Scalar>(x < y); });
		}

		template<typename Scalar>
		void SerialLessThan(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return static_cast<Scalar>(x < right); });
		}

		template<typename Scalar>
		void SerialLessThan(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return static_cast<Scalar>(left < x); });
		}

		template<typename Scalar>
		void SerialGreaterEqualThan(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return static_cast<Scalar>(x >= y); });
		}

		template<typename Scalar>
		void SerialGreaterEqualThan(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return static_cast<Scalar>(x >= right); });
		}

		template<typename Scalar>
		void SerialGreaterEqualThan(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return static_cast<Scalar>(left >= x); });
		}

		template<typename Scalar>
		void SerialLessEqualThan(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return static_cast<Scalar>(x <= y); });
		}

		template<typename Scalar>
		void SerialLessEqualThan(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return static_cast<Scalar>(x <= right); });
		}

		template<typename Scalar>
		void SerialLessEqualThan(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return static_cast<Scalar>(left <= x); });
		}

		template<typename Scalar>
		void SerialMaximum(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return std::max(x, y); });
		}

		template<typename Scalar>
		void SerialMaximum(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return std::max(x, right); });
		}

		template<typename Scalar>
		void SerialMaximum(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return std::max(left, x); });
		}

		template<typename Scalar>
		void SerialMinimum(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return std::min(x, y); });
		}

		template<typename Scalar>
		void SerialMinimum(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return std::min(x, right); });
		}

		template<typename Scalar>
		void SerialMinimum(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return std::min(left, x); });
		}

		template<typename Scalar>
		void SerialPow(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), right.cbegin(), result.begin(), [](Scalar x, Scalar y) { return std::pow(x, y); });
		}

		template<typename Scalar>
		void SerialPow(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result)
		{
			std::transform(left.cbegin(), left.cend(), result.begin(), [=](Scalar x) { return std::pow(x, right); });
		}

		template<typename Scalar>
		void SerialPow(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
		{
			std::transform(right.cbegin(), right.cend(), result.begin(), [=](Scalar x) { return std::pow(left, x); });
		}
	}
}
