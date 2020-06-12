#pragma once

#include "../Expr.hpp"
#include "../ReductionExpr.hpp"
#include "../LazyOPs.hpp"
#include "../../eager/reduction/EagerArgmin.hpp"
#include "../../../matrix/Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		Scalar Argmin(const tml::Matrix<Scalar>& matrix)
		{
			return tml::eager::Argmin(matrix);
		}

		template<typename Scalar, typename T>
		Scalar Argmin(const ExprOP<Scalar, T>& expr)
		{
			return tml::eager::Argmin(expr);
		}

		template<typename Scalar>
		ExprOP<Scalar, ReductionExpr<Scalar, tml::Matrix<Scalar>, ArgminRowsOP<Scalar, tml::Matrix<Scalar>>>>
			ArgminRows(const tml::Matrix<Scalar>& matrix)
		{
			typedef ReductionExpr<Scalar, tml::Matrix<Scalar>, ArgminRowsOP<Scalar, tml::Matrix<Scalar>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix), { 1, matrix.Rows() });
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, ReductionExpr<Scalar, ExprOP<Scalar, T>, ArgminRowsOP<Scalar, ExprOP<Scalar, T>>>>
			ArgminRows(const ExprOP<Scalar, T>& expr)
		{
			typedef ReductionExpr<Scalar, ExprOP<Scalar, T>, ArgminRowsOP<Scalar, ExprOP<Scalar, T>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), { 1, expr.Rows() });
		}

		template<typename Scalar>
		ExprOP<Scalar, ReductionExpr<Scalar, tml::Matrix<Scalar>, ArgminColsOP<Scalar, tml::Matrix<Scalar>>>>
			ArgminColumns(const tml::Matrix<Scalar>& matrix)
		{
			typedef ReductionExpr<Scalar, tml::Matrix<Scalar>, ArgminColsOP<Scalar, tml::Matrix<Scalar>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix), { 1, matrix.Columns() });
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, ReductionExpr<Scalar, ExprOP<Scalar, T>, ArgminColsOP<Scalar, ExprOP<Scalar, T>>>>
			ArgminColumns(const ExprOP<Scalar, T>& expr)
		{
			typedef ReductionExpr<Scalar, ExprOP<Scalar, T>, ArgminColsOP<Scalar, ExprOP<Scalar, T>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), { 1, expr.Columns() });
		}
	}
}
