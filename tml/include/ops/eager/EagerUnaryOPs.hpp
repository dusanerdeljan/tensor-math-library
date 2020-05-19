#pragma once

#include "serial\SerialUnaryOP.hpp"
#include "parallel\ParallelUnaryOP.hpp"
#include "..\lazy\Expr.hpp"

namespace tml
{
	namespace eager
	{
		template<typename Scalar, typename OP>
		tml::Matrix<Scalar> CustomUnaryOP(const tml::Matrix<Scalar>& matrix, OP&& op, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::CustomSerialUnaryOP(matrix, result, std::move(op));
			else
				details::ParallelCustomUnaryOP(matrix, result, std::move(op), parallelism);
			return result;
		}

		template<typename Scalar, typename T, typename OP>
		tml::Matrix<Scalar> CustomUnaryOP(const ExprOP<Scalar, T>& expr, OP&& op, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::CustomSerialUnaryOP(matrix, result, std::move(op));
			else
				details::ParallelCustomUnaryOP(matrix, result, std::move(op), parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Abs(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialAbs(matrix, result);
			else
				details::ParallelAbs(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Abs(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialAbs(matrix, result);
			else
				details::ParallelAbs(matrix, result, parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Cos(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCos(matrix, result);
			else
				details::ParallelCos(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Cos(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCos(matrix, result);
			else
				details::ParallelCos(matrix, result, parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Cosh(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCosh(matrix, result);
			else
				details::ParallelCosh(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Cosh(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCosh(matrix, result);
			else
				details::ParallelCosh(matrix, result, parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Cot(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCot(matrix, result);
			else
				details::ParallelCot(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Cot(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialCot(matrix, result);
			else
				details::ParallelCot(matrix, result, parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Exp(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialExp(matrix, result);
			else
				details::ParallelExp(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Exp(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialExp(matrix, result);
			else
				details::ParallelExp(matrix, result, parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Log(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialLog(matrix, result);
			else
				details::ParallelLog(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Log(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialLog(matrix, result);
			else
				details::ParallelLog(matrix, result, parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Neg(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialNeg(matrix, result);
			else
				details::ParallelNeg(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Neg(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialNeg(matrix, result);
			else
				details::ParallelNeg(matrix, result, parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Sin(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSin(matrix, result);
			else
				details::ParallelSin(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Sin(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSin(matrix, result);
			else
				details::ParallelSin(matrix, result, parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Sinh(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSinh(matrix, result);
			else
				details::ParallelSinh(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Sinh(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSinh(matrix, result);
			else
				details::ParallelSinh(matrix, result, parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Sqrt(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSqrt(matrix, result);
			else
				details::ParallelSqrt(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Sqrt(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSqrt(matrix, result);
			else
				details::ParallelSqrt(matrix, result, parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Square(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSquare(matrix, result);
			else
				details::ParallelSquare(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Square(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialSquare(matrix, result);
			else
				details::ParallelSquare(matrix, result, parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Tan(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialTan(matrix, result);
			else
				details::ParallelTan(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Tan(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialTan(matrix, result);
			else
				details::ParallelTan(matrix, result, parallelism);
			return result;
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Tanh(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialTanh(matrix, result);
			else
				details::ParallelTanh(matrix, result, parallelism);
			return result;
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Tanh(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				details::SerialTanh(matrix, result);
			else
				details::ParallelTanh(matrix, result, parallelism);
			return result;
		}
	}
}