#pragma once

#include <cmath>
#include <algorithm>
#include <limits>
#include "../eager/base/Base.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		struct AddOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return left + right; }
		};

		template<typename Scalar>
		struct SubOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return left - right; }
		};

		template<typename Scalar>
		struct MulOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return left*right; }
		};

		template<typename Scalar>
		struct DivOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return left / right; }
		};

		template<typename Scalar>
		struct EqualOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left == right); }
		};

		template<typename Scalar>
		struct NotEqualOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left != right); }
		};

		template<typename Scalar>
		struct GreaterThanOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left > right); }
		};

		template<typename Scalar>
		struct LessThanOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left < right); }
		};

		template<typename Scalar>
		struct GreaterEqualThanOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left >= right); }
		};

		template<typename Scalar>
		struct LessEqualThanOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left <= right); }
		};

		template<typename Scalar>
		struct MaximumOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return std::max(left, right); }
		};

		template<typename Scalar>
		struct MinimumOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return std::min(left, right); }
		};

		template<typename Scalar>
		struct PowOP
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return std::pow(left, right); }
		};

		template<typename Scalar>
		struct NegOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return -value; }
		};

		template<typename Scalar>
		struct LogOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::log(value)); }
		};

		template<typename Scalar>
		struct SqrtOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::sqrt(value)); }
		};

		template<typename Scalar>
		struct SquareOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return value*value; }
		};

		template<typename Scalar>
		struct ExpOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::exp(value)); }
		};

		template<typename Scalar>
		struct SinOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::sin(value)); }
		};

		template<typename Scalar>
		struct CosOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::cos(value)); }
		};

		template<typename Scalar>
		struct TanOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::tan(value)); }
		};

		template<typename Scalar>
		struct CotOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(1.0 / std::tan(value)); }
		};

		template<typename Scalar>
		struct SinhOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::sinh(value)); }
		};

		template<typename Scalar>
		struct CoshOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::cosh(value)); }
		};

		template<typename Scalar>
		struct TanhOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::tanh(value)); }
		};

		template<typename Scalar>
		struct AbsOP
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return std::abs(value); }
		};

		template<typename Scalar, typename Expr>
		struct SumRowsOP
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t row)
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
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t column)
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
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t row)
			{
				return SumRowsOP<Scalar, Expr>::op(expr, row) / expr.Columns();
			}
		};

		template<typename Scalar, typename Expr>
		struct MeanColsOP
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t column)
			{
				return SumColsOP<Scalar, Expr>::op(expr, column) / expr.Rows();
			}
		};

		template<typename Scalar, typename Expr>
		struct MinRowsOP
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t row)
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
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t column)
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
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t row)
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
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t column)
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

		template<typename Scalar, typename Expr>
		struct ArgminRowsOP
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t row)
			{
				size_t minIndex = 0;
				Scalar minValue = expr[minIndex + row*expr.Columns()];
				for (size_t i = 1; i < expr.Columns(); ++i)
				{
					Scalar current = expr[i + row*expr.Columns()];
					if (current <= minValue)
					{
						minValue = current;
						minIndex = i;
					}
				}
				return static_cast<Scalar>(minIndex);
			}
		};

		template<typename Scalar, typename Expr>
		struct ArgminColsOP
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t column)
			{
				size_t minIndex = 0;
				Scalar minValue = expr[column + minIndex*expr.Columns()];
				for (size_t i = 1; i < expr.Rows(); ++i)
				{
					Scalar current = expr[column + i*expr.Columns()];
					if (current <= minValue)
					{
						minValue = current;
						minIndex = i;
					}
				}
				return static_cast<Scalar>(minIndex);
			}
		};

		template<typename Scalar, typename Expr>
		struct ArgmaxRowsOP
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t row)
			{
				size_t maxIndex = 0;
				Scalar maxValue = expr[maxIndex + row*expr.Columns()];
				for (size_t i = 1; i < expr.Columns(); ++i)
				{
					Scalar current = expr[i + row*expr.Columns()];
					if (current >= maxValue)
					{
						maxValue = current;
						maxIndex = i;
					}
				}
				return static_cast<Scalar>(maxIndex);
			}
		};

		template<typename Scalar, typename Expr>
		struct ArgmaxColsOP
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t column)
			{
				size_t maxIndex = 0;
				Scalar maxValue = expr[column + maxIndex*expr.Columns()];
				for (size_t i = 1; i < expr.Rows(); ++i)
				{
					Scalar current = expr[column + i*expr.Columns()];
					if (current >= maxValue)
					{
						maxValue = current;
						maxIndex = i;
					}
				}
				return static_cast<Scalar>(maxIndex);
			}
		};
	}
}
