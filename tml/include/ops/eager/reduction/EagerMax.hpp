#pragma once

#include "../../lazy/Expr.hpp"
#include "../ExecutionPolicy.hpp"
#include "../serial/SerialMax.hpp"
#include "../parallel/ParallelMax.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE Scalar Max(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			Scalar result;
			details::backend::MaxBackend<Scalar, Backend>::Max(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE Scalar Max(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			const tml::Matrix<Scalar> matrix = expr;
			Scalar result;
			details::backend::MaxBackend<Scalar, Backend>::Max(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> MaxRows(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Rows() });
			details::backend::MaxBackend<Scalar, Backend>::Rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> MaxRows(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Rows });
			const tml::Matrix<Scalar> matrix = expr;
			details::backend::MaxBackend<Scalar, Backend>::Rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> MaxColumns(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Columns() });
			details::backend::MaxBackend<Scalar, Backend>::Columns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> MaxColumns(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Columns });
			const tml::Matrix<Scalar> matrix = expr;
			details::backend::MaxBackend<Scalar, Backend>::Columns(matrix, result);
			return result;
		}
	}
}