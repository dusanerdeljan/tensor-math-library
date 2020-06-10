#pragma once

#include "../Expr.hpp"
#include "../ReductionExpr.hpp"
#include "../LazyOPs.hpp"
#include "../../eager/reduction/EagerArgmax.hpp"
#include "../../../matrix/Matrix.hpp"

namespace tml
{
	namespace lazy
	{
		template<typename Scalar>
		Scalar Argmax(const tml::Matrix<Scalar>& matrix)
		{
			return tml::eager::Argmax(matrix, tml::PARALLEL);
		}

		template<typename Scalar, typename T>
		Scalar Argmax(const ExprOP<Scalar, T>& expr)
		{
			return tml::eager::Argmax(expr, tml::PARALLEL);
		}

		template<typename Scalar>
		ExprOP<Scalar, ReductionExpr<Scalar, tml::Matrix<Scalar>, ArgmaxRowsOP<Scalar, tml::Matrix<Scalar>>>>
			ArgmaxRows(const tml::Matrix<Scalar>& matrix)
		{
			typedef ReductionExpr<Scalar, tml::Matrix<Scalar>, ArgmaxRowsOP<Scalar, tml::Matrix<Scalar>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix), { 1, matrix.Rows() });
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, ReductionExpr<Scalar, ExprOP<Scalar, T>, ArgmaxRowsOP<Scalar, ExprOP<Scalar, T>>>>
			ArgmaxRows(const ExprOP<Scalar, T>& expr)
		{
			typedef ReductionExpr<Scalar, ExprOP<Scalar, T>, ArgmaxRowsOP<Scalar, ExprOP<Scalar, T>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), { 1, expr.Rows() });
		}

		template<typename Scalar>
		ExprOP<Scalar, ReductionExpr<Scalar, tml::Matrix<Scalar>, ArgmaxColsOP<Scalar, tml::Matrix<Scalar>>>>
			ArgmaxColumns(const tml::Matrix<Scalar>& matrix)
		{
			typedef ReductionExpr<Scalar, tml::Matrix<Scalar>, ArgmaxColsOP<Scalar, tml::Matrix<Scalar>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(matrix), { 1, matrix.Columns() });
		}

		template<typename Scalar, typename T>
		ExprOP<Scalar, ReductionExpr<Scalar, ExprOP<Scalar, T>, ArgmaxColsOP<Scalar, ExprOP<Scalar, T>>>>
			ArgmaxColumns(const ExprOP<Scalar, T>& expr)
		{
			typedef ReductionExpr<Scalar, ExprOP<Scalar, T>, ArgmaxColsOP<Scalar, ExprOP<Scalar, T>>> ExprType;
			return ExprOP<Scalar, ExprType>(ExprType(expr), { 1, expr.Columns() });
		}
	}
}
