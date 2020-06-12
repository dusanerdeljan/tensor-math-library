#pragma once

#include "../Expr.hpp"
#include "../ReductionExpr.hpp"
#include "../LazyOPs.hpp"
#include "../../eager/reduction/EagerMin.hpp"
#include "../../../matrix/Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		Scalar Min(const tml::Matrix<Scalar>& matrix)
		{
			return tml::eager::Min(matrix);
		}

		template<typename Scalar, typename T>
		Scalar Min(const ExprOP<Scalar, T>& expr)
		{
			return tml::eager::Min(expr);
		}

		template<typename Scalar>
		ExprOP<Scalar, ReductionExpr<Scalar, tml::Matrix<Scalar>, MinRowsOP<Scalar, tml::Matrix<Scalar>>>>
			MinRows(const tml::Matrix<Scalar>& matrix)
		{
			typedef ReductionExpr<Scalar, tml::Matrix<Scalar>, MinRowsOP<Scalar, tml::Matrix<Scalar>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix), { 1, matrix.Rows() });
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, ReductionExpr<Scalar, ExprOP<Scalar, T>, MinRowsOP<Scalar, ExprOP<Scalar, T>>>>
			MinRows(const ExprOP<Scalar, T>& expr)
		{
			typedef ReductionExpr<Scalar, ExprOP<Scalar, T>, MinRowsOP<Scalar, ExprOP<Scalar, T>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), { 1, expr.Rows() });
		}

		template<typename Scalar>
		ExprOP<Scalar, ReductionExpr<Scalar, tml::Matrix<Scalar>, MinColsOP<Scalar, tml::Matrix<Scalar>>>>
			MinColumns(const tml::Matrix<Scalar>& matrix)
		{
			typedef ReductionExpr<Scalar, tml::Matrix<Scalar>, MinColsOP<Scalar, tml::Matrix<Scalar>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix), { 1, matrix.Columns() });
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, ReductionExpr<Scalar, ExprOP<Scalar, T>, MinColsOP<Scalar, ExprOP<Scalar, T>>>>
			MinColumns(const ExprOP<Scalar, T>& expr)
		{
			typedef ReductionExpr<Scalar, ExprOP<Scalar, T>, MinColsOP<Scalar, ExprOP<Scalar, T>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), { 1, expr.Columns() });
		}
	}
}
