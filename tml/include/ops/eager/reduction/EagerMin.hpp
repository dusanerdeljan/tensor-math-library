#pragma once

#include "../../lazy/Expr.hpp"
#include "../ExecutionPolicy.hpp"
#include "../serial/SerialMin.hpp"
#include "../parallel/ParallelMin.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE Scalar Min(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			Scalar result;
			details::backend::MinBackend<Scalar, Backend>::Min(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE Scalar Min(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			const tml::Matrix<Scalar> matrix = expr;
			Scalar result;
			details::backend::MinBackend<Scalar, Backend>::Min(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> MinRows(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Rows() });
			details::backend::MinBackend<Scalar, Backend>::Rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> MinRows(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Rows });
			const tml::Matrix<Scalar> matrix = expr;
			details::backend::MinBackend<Scalar, Backend>::Rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> MinColumns(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Columns() });
			details::backend::MinBackend<Scalar, Backend>::Columns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> MinColumns(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Columns });
			const tml::Matrix<Scalar> matrix = expr;
			details::backend::MinBackend<Scalar, Backend>::Columns(matrix, result);
			return result;
		}
	}
}