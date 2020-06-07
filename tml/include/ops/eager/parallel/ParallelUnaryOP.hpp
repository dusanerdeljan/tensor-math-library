#pragma once

#include "backends\tbb\UnaryOP.hpp"
#include "backends\omp\UnaryOP.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar, typename Backend>
			void ParallelAbs(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}

			template<typename Scalar, typename Backend>
			void ParallelCos(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}

			template<typename Scalar, typename Backend>
			void ParallelCosh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}

			template<typename Scalar, typename Backend>
			void ParallelCot(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}

			template<typename Scalar, typename Backend>
			void ParallelExp(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}

			template<typename Scalar, typename Backend>
			void ParallelLog(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}

			template<typename Scalar, typename Backend>
			void ParallelNeg(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}

			template<typename Scalar, typename Backend>
			void ParallelSin(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}

			template<typename Scalar, typename Backend>
			void ParallelSinh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}

			template<typename Scalar, typename Backend>
			void ParallelSqrt(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}

			template<typename Scalar, typename Backend>
			void ParallelSquare(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}

			template<typename Scalar, typename Backend>
			void ParallelTan(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}

			template<typename Scalar, typename Backend>
			void ParallelTanh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, Backend backend)
			{
				backend::UnaryOPBackend<Scalar, Backend>::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
			}
		}
	}
}
