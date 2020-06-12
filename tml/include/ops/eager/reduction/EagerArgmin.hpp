#pragma once

#include "../../lazy/Expr.hpp"
#include "../ExecutionPolicy.hpp"
#include "../serial/SerialArgmin.hpp"
#include "../parallel/ParallelArgmin.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE Scalar Argmin(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			Scalar result;
			details::backend::ArgminBackend<Scalar, Backend>::Argmin(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE Scalar Argmin(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			const tml::Matrix<Scalar> matrix = expr;
			Scalar result;
			details::backend::ArgminBackend<Scalar, Backend>::Argmin(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> ArgminRows(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Rows() });
			details::backend::ArgminBackend<Scalar, Backend>::Rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> ArgminRows(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Rows });
			const tml::Matrix<Scalar> matrix = expr;
			details::backend::ArgminBackend<Scalar, Backend>::Rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> ArgminColumns(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Columns() });
			details::backend::ArgminBackend<Scalar, Backend>::Columns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> ArgminColumns(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Columns });
			const tml::Matrix<Scalar> matrix = expr;
			details::backend::ArgminBackend<Scalar, Backend>::Columns(matrix, result);
			return result;
		}
	}
}