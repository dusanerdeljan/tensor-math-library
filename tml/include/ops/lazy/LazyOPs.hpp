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
		struct add_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return left + right; }
		};

		template<typename Scalar>
		struct sub_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return left - right; }
		};

		template<typename Scalar>
		struct mul_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return left*right; }
		};

		template<typename Scalar>
		struct div_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return left / right; }
		};

		template<typename Scalar>
		struct equal_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left == right); }
		};

		template<typename Scalar>
		struct not_equal_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left != right); }
		};

		template<typename Scalar>
		struct greater_than_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left > right); }
		};

		template<typename Scalar>
		struct less_than_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left < right); }
		};

		template<typename Scalar>
		struct greater_equal_than_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left >= right); }
		};

		template<typename Scalar>
		struct less_equal_than_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return static_cast<Scalar>(left <= right); }
		};

		template<typename Scalar>
		struct maximum_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return std::max(left, right); }
		};

		template<typename Scalar>
		struct minimum_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return std::min(left, right); }
		};

		template<typename Scalar>
		struct pow_op
		{
			TML_STRONG_INLINE Scalar op(Scalar left, Scalar right) { return std::pow(left, right); }
		};

		template<typename Scalar>
		struct neg_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return -value; }
		};

		template<typename Scalar>
		struct log_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::log(value)); }
		};

		template<typename Scalar>
		struct sqrt_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::sqrt(value)); }
		};

		template<typename Scalar>
		struct square_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return value*value; }
		};

		template<typename Scalar>
		struct exp_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::exp(value)); }
		};

		template<typename Scalar>
		struct sin_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::sin(value)); }
		};

		template<typename Scalar>
		struct cos_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::cos(value)); }
		};

		template<typename Scalar>
		struct tan_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::tan(value)); }
		};

		template<typename Scalar>
		struct cot_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(1.0 / std::tan(value)); }
		};

		template<typename Scalar>
		struct sinh_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::sinh(value)); }
		};

		template<typename Scalar>
		struct cosh_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::cosh(value)); }
		};

		template<typename Scalar>
		struct tanh_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return static_cast<Scalar>(std::tanh(value)); }
		};

		template<typename Scalar>
		struct abs_op
		{
			TML_STRONG_INLINE Scalar op(Scalar value) { return std::abs(value); }
		};

		template<typename Scalar, typename Expr>
		struct sum_rows_op
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t row)
			{
				Scalar sum = static_cast<Scalar>(0);
				for (size_t i = 0; i < expr.columns(); ++i)
					sum += expr[i + row*expr.columns()];
				return sum;
			}
		};

		template<typename Scalar, typename Expr>
		struct sum_cols_op
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t column)
			{
				Scalar sum = static_cast<Scalar>(0);
				for (size_t i = 0; i < expr.rows(); ++i)
					sum += expr[column + i*expr.columns()];
				return sum;
			}
		};

		template<typename Scalar, typename Expr>
		struct mean_rows_op
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t row)
			{
				return sum_rows_op<Scalar, Expr>::op(expr, row) / expr.columns();
			}
		};

		template<typename Scalar, typename Expr>
		struct mean_cols_op
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t column)
			{
				return sum_cols_op<Scalar, Expr>::op(expr, column) / expr.rows();
			}
		};

		template<typename Scalar, typename Expr>
		struct min_rows_op
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t row)
			{
				Scalar minValue = (std::numeric_limits<Scalar>::max)();
				for (size_t i = 0; i < expr.columns(); ++i)
				{
					Scalar current = expr[i + row*expr.columns()];
					if (current < minValue) minValue = current;
				}
				return minValue;
			}
		};

		template<typename Scalar, typename Expr>
		struct min_cols_op
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t column)
			{
				Scalar minValue = (std::numeric_limits<Scalar>::max)();
				for (size_t i = 0; i < expr.rows(); ++i)
				{
					Scalar current = expr[column + i*expr.columns()];
					if (current < minValue) minValue = current;
				}
				return minValue;
			}
		};

		template<typename Scalar, typename Expr>
		struct max_rows_op
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t row)
			{
				Scalar maxValue = (std::numeric_limits<Scalar>::min)();
				for (size_t i = 0; i < expr.columns(); ++i)
				{
					Scalar current = expr[i + row*expr.columns()];
					if (current > maxValue) maxValue = current;
				}
				return maxValue;
			}
		};

		template<typename Scalar, typename Expr>
		struct max_cols_op
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t column)
			{
				Scalar maxValue = (std::numeric_limits<Scalar>::min)();
				for (size_t i = 0; i < expr.rows(); ++i)
				{
					Scalar current = expr[column + i*expr.columns()];
					if (current > maxValue) maxValue = current;
				}
				return maxValue;
			}
		};

		template<typename Scalar, typename Expr>
		struct argmin_rows_op
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t row)
			{
				size_t minIndex = 0;
				Scalar minValue = expr[minIndex + row*expr.columns()];
				for (size_t i = 1; i < expr.columns(); ++i)
				{
					Scalar current = expr[i + row*expr.columns()];
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
		struct argmin_cols_op
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t column)
			{
				size_t minIndex = 0;
				Scalar minValue = expr[column + minIndex*expr.columns()];
				for (size_t i = 1; i < expr.rows(); ++i)
				{
					Scalar current = expr[column + i*expr.columns()];
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
		struct argmax_rows_op
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t row)
			{
				size_t maxIndex = 0;
				Scalar maxValue = expr[maxIndex + row*expr.columns()];
				for (size_t i = 1; i < expr.columns(); ++i)
				{
					Scalar current = expr[i + row*expr.columns()];
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
		struct argmax_cols_op
		{
			TML_STRONG_INLINE Scalar op(const Expr& expr, size_t column)
			{
				size_t maxIndex = 0;
				Scalar maxValue = expr[column + maxIndex*expr.columns()];
				for (size_t i = 1; i < expr.rows(); ++i)
				{
					Scalar current = expr[column + i*expr.columns()];
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
