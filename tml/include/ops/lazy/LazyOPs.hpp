#pragma once
#include <algorithm>

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		struct AddOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return left + right; }
		};

		template<typename Scalar>
		struct SubOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return left - right; }
		};

		template<typename Scalar>
		struct MulOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return left*right; }
		};

		template<typename Scalar>
		struct DivOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return left / right; }
		};

		template<typename Scalar>
		struct EqualOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left == right); }
		};

		template<typename Scalar>
		struct NotEqualOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left != right); }
		};

		template<typename Scalar>
		struct GreaterThanOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left > right); }
		};

		template<typename Scalar>
		struct LessThanOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left < right); }
		};

		template<typename Scalar>
		struct GreaterEqualThanOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left >= right); }
		};

		template<typename Scalar>
		struct LessEqualThanOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left <= right); }
		};

		template<typename Scalar>
		struct MaximumOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return std::max(left, right); }
		};

		template<typename Scalar>
		struct MinimumOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return std::min(left, right); }
		};

		template<typename Scalar>
		struct NegOP
		{
			static inline Scalar op(Scalar value) { return -value; }
		};

		template<typename Scalar>
		struct LogOP
		{
			static inline Scalar op(Scalar value) { return static_cast<Scalar>(std::log(value)); }
		};

		template<typename Scalar>
		struct SqrtOP
		{
			static inline Scalar op(Scalar value) { return static_cast<Scalar>(std::sqrt(value)); }
		};

		template<typename Scalar>
		struct SquareOP
		{
			static inline Scalar op(Scalar value) { return value*value; }
		};

		template<typename Scalar>
		struct ExpOP
		{
			static inline Scalar op(Scalar value) { return static_cast<Scalar>(std::exp(value)); }
		};

		template<typename Scalar>
		struct SinOP
		{
			static inline Scalar op(Scalar value) { return static_cast<Scalar>(std::sin(value)); }
		};

		template<typename Scalar>
		struct CosOP
		{
			static inline Scalar op(Scalar value) { return static_cast<Scalar>(std::cos(value)); }
		};

		template<typename Scalar>
		struct TanOP
		{
			static inline Scalar op(Scalar value) { return static_cast<Scalar>(std::tan(value)); }
		};

		template<typename Scalar>
		struct CotOP
		{
			static inline Scalar op(Scalar value) { return static_cast<Scalar>(1.0 / std::tan(value)); }
		};

		template<typename Scalar>
		struct SinhOP
		{
			static inline Scalar op(Scalar value) { return static_cast<Scalar>(std::sinh(value)); }
		};

		template<typename Scalar>
		struct CoshOP
		{
			static inline Scalar op(Scalar value) { return static_cast<Scalar>(std::cosh(value)); }
		};

		template<typename Scalar>
		struct TanhOP
		{
			static inline Scalar op(Scalar value) { return static_cast<Scalar>(std::tanh(value)); }
		};

		template<typename Scalar>
		struct AbsOP
		{
			static inline Scalar op(Scalar value) { return std::abs(value); }
		};
	}
}
