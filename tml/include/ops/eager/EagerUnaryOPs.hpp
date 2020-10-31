#pragma once

#include "serial/SerialUnaryOP.hpp"
#include "parallel/ParallelUnaryOP.hpp"
#include "../lazy/Expr.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename OP, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> custom_unary_op(const tml::matrix<Scalar>& matrix, OP&& op, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, std::move(op));
			return result;
		}

		template<typename Scalar, typename T, typename OP, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> custom_unary_op(const expr_op<Scalar, T>& expr, OP&& op, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, std::move(op));
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> abs(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return std::abs(x); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> abs(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return std::abs(x); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> cos(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cos(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> cos(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cos(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> cosh(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cosh(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> cosh(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cosh(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> cot(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cosh(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> cot(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(1.0 / std::tan(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> exp(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::exp(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> exp(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::exp(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> log(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::log(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> log(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::log(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> neg(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return -x; });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> neg(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return -x; });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> sin(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sin(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> sin(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sin(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> sinh(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sinh(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> sinh(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sinh(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> sqrt(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sqrt(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> sqrt(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sqrt(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> square(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return x*x; });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> square(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return x*x; });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> tan(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tan(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> tan(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tan(x)); });
			return result;
		}


		template<typename Scalar, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> tanh(const tml::matrix<Scalar>& matrix, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tan(x)); });
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::SEQ>
		TML_INLINE tml::matrix<Scalar> tanh(const expr_op<Scalar, T>& expr, Backend = tml::execution::seq)
		{
			tml::matrix<Scalar> matrix = expr;
			tml::matrix<Scalar> result(matrix.get_shape());
			details::backend::unary_op_backend<Scalar, Backend>::do_op(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tan(x)); });
			return result;
		}
	}
}