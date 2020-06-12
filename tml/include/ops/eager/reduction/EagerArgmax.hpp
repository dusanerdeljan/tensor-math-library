#pragma once

#include "../../lazy/Expr.hpp"
#include "../ExecutionPolicy.hpp"
#include "../serial/SerialArgmax.hpp"
#include "../parallel/ParallelArgmax.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE Scalar Argmax(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			Scalar result;
			details::backend::ArgmaxBackend<Scalar, Backend>::Argmax(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE Scalar Argmax(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			const tml::Matrix<Scalar> matrix = expr;
			Scalar result;
			details::backend::ArgmaxBackend<Scalar, Backend>::Argmax(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> ArgmaxRows(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Rows() });
			details::backend::ArgmaxBackend<Scalar, Backend>::Rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> ArgmaxRows(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Rows });
			const tml::Matrix<Scalar> matrix = expr;
			details::backend::ArgmaxBackend<Scalar, Backend>::Rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> ArgmaxColumns(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Columns() });
			details::backend::ArgmaxBackend<Scalar, Backend>::Columns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> ArgmaxColumns(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Columns });
			const tml::Matrix<Scalar> matrix = expr;
			details::backend::ArgmaxBackend<Scalar, Backend>::Columns(matrix, result);
			return result;
		}
	}
}