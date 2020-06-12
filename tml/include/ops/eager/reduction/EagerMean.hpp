#pragma once

#include "../../lazy/Expr.hpp"
#include "../ExecutionPolicy.hpp"
#include "../serial/SerialMean.hpp"
#include "../parallel/ParallelMean.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE Scalar Mean(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			Scalar result;
			details::backend::MeanBackend<Scalar, Backend>::Mean(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE Scalar Mean(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			const tml::Matrix<Scalar> matrix = expr;
			Scalar result;
			details::backend::MeanBackend<Scalar, Backend>::Mean(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> MeanRows(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Rows() });
			details::backend::MeanBackend<Scalar, Backend>::Rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> MeanRows(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Rows });
			const tml::Matrix<Scalar> matrix = expr;
			details::backend::MeanBackend<Scalar, Backend>::Rows(matrix, result);
			return result;
		}

		template<typename Scalar, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> MeanColumns(const tml::Matrix<Scalar>& matrix, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, matrix.Columns() });
			details::backend::MeanBackend<Scalar, Backend>::Columns(matrix, result);
			return result;
		}

		template<typename Scalar, typename T, typename Backend = details::SEQ>
		TML_INLINE tml::Matrix<Scalar> MeanColumns(const ExprOP<Scalar, T>& expr, Backend backend = tml::execution::seq)
		{
			tml::Matrix<Scalar> result(Shape{ 1, expr.shape.Columns });
			const tml::Matrix<Scalar> matrix = expr;
			details::backend::MeanBackend<Scalar, Backend>::Columns(matrix, result);
			return result;
		}
	}
}