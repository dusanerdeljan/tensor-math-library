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
				CustomSerialUnaryOP(matrix, result, std::move(op));
			else
				ParallelCustomUnaryOP(matrix, result, std::move(op), parallelism);
			return std::move(result);
		}

		template<typename Scalar, typename T, typename OP>
		tml::Matrix<Scalar> CustomUnaryOP(const ExprOP<Scalar, T>& expr, OP&& op, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				CustomSerialUnaryOP(matrix, result, std::move(op));
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Abs(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialAbs(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Abs(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialAbs(matrix, result);
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Cos(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialCos(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Cos(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialCos(matrix, result);
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Cosh(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialCosh(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Cosh(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialCosh(matrix, result);
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Cot(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialCot(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Cot(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialCot(matrix, result);
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Exp(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialExp(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Exp(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialExp(matrix, result);
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Log(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialLog(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Log(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialLog(matrix, result);
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Neg(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialNeg(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Neg(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialNeg(matrix, result);
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Sin(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialSin(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Sin(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialSin(matrix, result);
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Sinh(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialSinh(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Sinh(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialSinh(matrix, result);
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Sqrt(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialSqrt(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Sqrt(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialSqrt(matrix, result);
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Square(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialSquare(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Square(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialSquare(matrix, result);
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Tan(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialTan(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Tan(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialTan(matrix, result);
			return std::move(result);
		}


		template<typename Scalar>
		tml::Matrix<Scalar> Tanh(const tml::Matrix<Scalar>& matrix, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialTanh(matrix, result);
			return std::move(result);
		}

		template<typename Scalar, typename T>
		tml::Matrix<Scalar> Tanh(const ExprOP<Scalar, T>& expr, tml::ExecutionPolicy execPolicy = tml::SERIAL, tml::ParallelismPolicy parallelism = tml::ONE_OVER_CORES)
		{
			tml::Matrix<Scalar> matrix = expr;
			tml::Matrix<Scalar> result(matrix.GetShape());
			if (execPolicy == tml::SERIAL)
				SerialTanh(matrix, result);
			return std::move(result);
		}
	}
}