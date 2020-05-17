#pragma once

#include "..\Expr.hpp"
#include "..\ReductionExpr.hpp"
#include "..\LazyOPs.hpp"
#include "..\..\eager\EagerSum.hpp"
#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		Scalar Sum(const tml::Matrix<Scalar>& matrix)
		{
			return tml::eager::Sum(matrix, tml::PARALLEL);
		}

		template<typename Scalar, typename T>
		Scalar Sum(const ExprOP<Scalar, T>& expr)
		{
			return tml::eager::Sum(expr, tml::PARALLEL);
		}

		template<typename Scalar>
		ExprOP<Scalar, ReductionExpr<Scalar, tml::Matrix<Scalar>, SumRowsOP<Scalar, tml::Matrix<Scalar>>>>
			SumRows(const tml::Matrix<Scalar>& matrix)
		{
			typedef ReductionExpr<Scalar, tml::Matrix<Scalar>, SumRowsOP<Scalar, tml::Matrix<Scalar>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix), { 1, matrix.Rows() });
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, ReductionExpr<Scalar, ExprOP<Scalar, T>, SumRowsOP<Scalar, ExprOP<Scalar, T>>>>
			SumRows(const ExprOP<Scalar, T>& expr)
		{
			typedef ReductionExpr<Scalar, ExprOP<Scalar, T>, SumRowsOP<Scalar, ExprOP<Scalar, T>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), { 1, expr.Rows() });
		}

		template<typename Scalar>
		ExprOP<Scalar, ReductionExpr<Scalar, tml::Matrix<Scalar>, SumColsOP<Scalar, tml::Matrix<Scalar>>>>
			SumColumns(const tml::Matrix<Scalar>& matrix)
		{
			typedef ReductionExpr<Scalar, tml::Matrix<Scalar>, SumColsOP<Scalar, tml::Matrix<Scalar>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix), { 1, matrix.Columns() });
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, ReductionExpr<Scalar, ExprOP<Scalar, T>, SumColsOP<Scalar, ExprOP<Scalar, T>>>>
			SumColumns(const ExprOP<Scalar, T>& expr)
		{
			typedef ReductionExpr<Scalar, ExprOP<Scalar, T>, SumColsOP<Scalar, ExprOP<Scalar, T>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), { 1, expr.Columns() });
		}
	}
}
