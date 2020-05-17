#pragma once
#include <algorithm>
#include <limits>

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
		struct PowOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return std::pow(left, right); }
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

		template<typename Scalar, typename Expr>
		struct SumRowsOP
		{
			static inline Scalar op(const Expr& expr, size_t row)
			{
				Scalar sum = static_cast<Scalar>(0);
				for (size_t i = 0; i < expr.Columns(); ++i)
					sum += expr[i + row*expr.Columns()];
				return sum;
			}
		};

		template<typename Scalar, typename Expr>
		struct SumColsOP
		{
			static inline Scalar op(const Expr& expr, size_t column)
			{
				Scalar sum = static_cast<Scalar>(0);
				for (size_t i = 0; i < expr.Rows(); ++i)
					sum += expr[column + i*expr.Columns()];
				return sum;
			}
		};

		template<typename Scalar, typename Expr>
		struct MeanRowsOP
		{
			static inline Scalar op(const Expr& expr, size_t row)
			{
				return SumRowsOP<Scalar, Expr>::op(expr, row) / expr.Columns();
			}
		};

		template<typename Scalar, typename Expr>
		struct MeanColsOP
		{
			static inline Scalar op(const Expr& expr, size_t column)
			{
				return SumColsOP<Scalar, Expr>::op(expr, column) / expr.Rows();
			}
		};

		template<typename Scalar, typename Expr>
		struct MinRowsOP
		{
			static inline Scalar op(const Expr& expr, size_t row)
			{
				Scalar minValue = (std::numeric_limits<Scalar>::max)();
				for (size_t i = 0; i < expr.Columns(); ++i)
				{
					Scalar current = expr[i + row*expr.Columns()];
					if (current < minValue) minValue = current;
				}
				return minValue;
			}
		};

		template<typename Scalar, typename Expr>
		struct MinColsOP
		{
			static inline Scalar op(const Expr& expr, size_t column)
			{
				Scalar minValue = (std::numeric_limits<Scalar>::max)();
				for (size_t i = 0; i < expr.Rows(); ++i)
				{
					Scalar current = expr[column + i*expr.Columns()];
					if (current < minValue) minValue = current;
				}
				return minValue;
			}
		};

		template<typename Scalar, typename Expr>
		struct MaxRowsOP
		{
			static inline Scalar op(const Expr& expr, size_t row)
			{
				Scalar maxValue = (std::numeric_limits<Scalar>::min)();
				for (size_t i = 0; i < expr.Columns(); ++i)
				{
					Scalar current = expr[i + row*expr.Columns()];
					if (current > maxValue) maxValue = current;
				}
				return maxValue;
			}
		};

		template<typename Scalar, typename Expr>
		struct MaxColsOP
		{
			static inline Scalar op(const Expr& expr, size_t column)
			{
				Scalar maxValue = (std::numeric_limits<Scalar>::min)();
				for (size_t i = 0; i < expr.Rows(); ++i)
				{
					Scalar current = expr[column + i*expr.Columns()];
					if (current > maxValue) maxValue = current;
				}
				return maxValue;
			}
		};
	}
}
