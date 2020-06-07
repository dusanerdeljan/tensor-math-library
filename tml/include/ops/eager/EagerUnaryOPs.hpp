#pragma once

#include "serial\SerialUnaryOP.hpp"
#include "parallel\ParallelUnaryOP.hpp"
#include "..\lazy\Expr.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename OP, typename Backend=details::TBB>
		tml::Matrix<Scalar> CustomUnaryOP(const tml::Matrix<Scalar>& matrix, OP&& op, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::CustomSerialUnaryOP(matrix, result, std::move(op));
			else
				details::ParallelCustomUnaryOP(matrix, result, std::move(op), backend);
			return result;
		}

		template<typename Scalar, typename T, typename OP, typename Backend=details::TBB>
		tml::Matrix<Scalar> CustomUnaryOP(const ExprOP<Scalar, T>& expr, OP&& op, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::CustomSerialUnaryOP(matrix, result, std::move(op));
			else
				details::ParallelCustomUnaryOP(matrix, result, std::move(op), backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Abs(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialAbs(matrix, result);
			else
				details::ParallelAbs(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Abs(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialAbs(matrix, result);
			else
				details::ParallelAbs(matrix, result, backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Cos(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCos(matrix, result);
			else
				details::ParallelCos(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Cos(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCos(matrix, result);
			else
				details::ParallelCos(matrix, result, backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Cosh(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCosh(matrix, result);
			else
				details::ParallelCosh(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Cosh(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCosh(matrix, result);
			else
				details::ParallelCosh(matrix, result, backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Cot(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCot(matrix, result);
			else
				details::ParallelCot(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Cot(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCot(matrix, result);
			else
				details::ParallelCot(matrix, result, backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Exp(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialExp(matrix, result);
			else
				details::ParallelExp(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Exp(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialExp(matrix, result);
			else
				details::ParallelExp(matrix, result, backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Log(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialLog(matrix, result);
			else
				details::ParallelLog(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Log(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialLog(matrix, result);
			else
				details::ParallelLog(matrix, result, backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Neg(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialNeg(matrix, result);
			else
				details::ParallelNeg(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Neg(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialNeg(matrix, result);
			else
				details::ParallelNeg(matrix, result, backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Sin(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSin(matrix, result);
			else
				details::ParallelSin(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Sin(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSin(matrix, result);
			else
				details::ParallelSin(matrix, result, backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Sinh(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSinh(matrix, result);
			else
				details::ParallelSinh(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Sinh(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSinh(matrix, result);
			else
				details::ParallelSinh(matrix, result, backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Sqrt(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSqrt(matrix, result);
			else
				details::ParallelSqrt(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Sqrt(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSqrt(matrix, result);
			else
				details::ParallelSqrt(matrix, result, backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Square(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSquare(matrix, result);
			else
				details::ParallelSquare(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Square(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSquare(matrix, result);
			else
				details::ParallelSquare(matrix, result, backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Tan(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialTan(matrix, result);
			else
				details::ParallelTan(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Tan(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialTan(matrix, result);
			else
				details::ParallelTan(matrix, result, backend);
			return result;
		}


		template<typename Scalar, typename Backend=details::TBB>
		tml::Matrix<Scalar> Tanh(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialTanh(matrix, result);
			else
				details::ParallelTanh(matrix, result, backend);
			return result;
		}

		template<typename Scalar, typename T, typename Backend=details::TBB>
		tml::Matrix<Scalar> Tanh(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, Backend backend = tml::execution::tbb)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialTanh(matrix, result);
			else
				details::ParallelTanh(matrix, result, backend);
			return result;
		}
	}
}