#pragma once

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
		struct LogOP
		{
			static inline Scalar op(Scalar value) { return std::log(value); }
		};

		template<typename Scalar>
		struct SqrtOP
		{
			static inline Scalar op(Scalar value) { return std::sqrt(value); }
		};

		template<typename Scalar>
		struct SquareOP
		{
			static inline Scalar op(Scalar value) { return value*value; }
		};

		template<typename Scalar>
		struct ExpOP
		{
			static inline Scalar op(Scalar value) { return std::exp(value); }
		};

		template<typename Scalar>
		struct SinOP
		{
			static inline Scalar op(Scalar value) { return std::sin(value); }
		};

		template<typename Scalar>
		struct CosOP
		{
			static inline Scalar op(Scalar value) { return std::cos(value); }
		};
	}
}
