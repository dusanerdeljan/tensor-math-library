#pragma once

#include "backends\tbb\TBBBackend.hpp"
#include "backends\omp\OMPBackend.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar>
			void ParallelAbs(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); }, parallelism);
			}

			template<typename Scalar>
			void ParallelCos(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cos(x)); }, parallelism);
			}

			template<typename Scalar>
			void ParallelCosh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cosh(x)); }, parallelism);
			}

			template<typename Scalar>
			void ParallelCot(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(1.0 / std::tan(x)); }, parallelism);
			}

			template<typename Scalar>
			void ParallelExp(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::exp(x)); }, parallelism);
			}

			template<typename Scalar>
			void ParallelLog(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::log(x)); }, parallelism);
			}

			template<typename Scalar>
			void ParallelNeg(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return -x }, parallelism);
			}

			template<typename Scalar>
			void ParallelSin(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sin(x)); }, parallelism);
			}

			template<typename Scalar>
			void ParallelSinh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sinh(x)); }, parallelism);
			}

			template<typename Scalar>
			void ParallelSqrt(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sqrt(x)); }, parallelism);
			}

			template<typename Scalar>
			void ParallelSquare(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return x*x; }, parallelism);
			}

			template<typename Scalar>
			void ParallelTan(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tan(x)); }, parallelism);
			}

			template<typename Scalar>
			void ParallelTanh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tanh(x)); }, parallelism);
			}
		}
	}
}
