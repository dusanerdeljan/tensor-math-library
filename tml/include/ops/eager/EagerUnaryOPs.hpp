#pragma once

#include "serial\SerialUnaryOP.hpp"
#include "parallel\backends\tbb\UnaryOP.hpp"
#include "parallel\backends\omp\UnaryOP.hpp"
#include "..\lazy\Expr.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename OP, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> CustomUnaryOP(const tml::Matrix<Scalar>& matrix, OP&& op, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, std::move(op));
			return result;
		}

		template<typename Scalar, typename T, typename OP, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> CustomUnaryOP(const ExprOP<Scalar, T>& expr, OP&& op, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, std::move(op));
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Abs(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return std::abs(x); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Abs(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return std::abs(x); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Cos(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cos(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Cos(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cos(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Cosh(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cosh(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Cosh(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cosh(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Cot(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cosh(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Cot(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(1.0 / std::tan(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Exp(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::exp(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Exp(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::exp(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Log(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::log(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Log(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::log(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Neg(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return -x; });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Neg(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return -x; });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Sin(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sin(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Sin(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sin(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Sinh(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sinh(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Sinh(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sinh(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Sqrt(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sqrt(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Sqrt(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sqrt(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Square(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return x*x; });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Square(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return x*x; });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Tan(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tan(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Tan(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tan(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Tanh(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tan(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::Matrix<Scalar> Tanh(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			details::backend::UnaryOPBackend<Scalar, Backend>::DoOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tan(x)); });
			return result;
		}
	}
}