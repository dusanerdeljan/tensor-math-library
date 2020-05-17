#pragma once

#include "..\Expr.hpp"
#include "..\ReductionExpr.hpp"
#include "..\LazyOPs.hpp"
#include "..\..\eager\EagerMax.hpp"
#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		Scalar Max(const tml::Matrix<Scalar>& matrix)
		{
			return tml::eager::Max(matrix, tml::PARALLEL);
		}

		template<typename Scalar, typename T>
		Scalar Max(const ExprOP<Scalar, T>& expr)
		{
			return tml::eager::Max(expr, tml::PARALLEL);
		}

		template<typename Scalar>
		ExprOP<Scalar, ReductionExpr<Scalar, tml::Matrix<Scalar>, MaxRowsOP<Scalar, tml::Matrix<Scalar>>>>
			MaxRows(const tml::Matrix<Scalar>& matrix)
		{
			typedef ReductionExpr<Scalar, tml::Matrix<Scalar>, MaxRowsOP<Scalar, tml::Matrix<Scalar>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix), { 1, matrix.Rows() });
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, ReductionExpr<Scalar, ExprOP<Scalar, T>, MaxRowsOP<Scalar, ExprOP<Scalar, T>>>>
			MaxRows(const ExprOP<Scalar, T>& expr)
		{
			typedef ReductionExpr<Scalar, ExprOP<Scalar, T>, MaxRowsOP<Scalar, ExprOP<Scalar, T>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), { 1, expr.Rows() });
		}

		template<typename Scalar>
		ExprOP<Scalar, ReductionExpr<Scalar, tml::Matrix<Scalar>, MaxColsOP<Scalar, tml::Matrix<Scalar>>>>
			MaxColumns(const tml::Matrix<Scalar>& matrix)
		{
			typedef ReductionExpr<Scalar, tml::Matrix<Scalar>, MaxColsOP<Scalar, tml::Matrix<Scalar>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix), { 1, matrix.Columns() });
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, ReductionExpr<Scalar, ExprOP<Scalar, T>, MaxColsOP<Scalar, ExprOP<Scalar, T>>>>
			MaxColumns(const ExprOP<Scalar, T>& expr)
		{
			typedef ReductionExpr<Scalar, ExprOP<Scalar, T>, MaxColsOP<Scalar, ExprOP<Scalar, T>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), { 1, expr.Columns() });
		}
	}
}
