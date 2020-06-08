#pragma once

#include "backends\tbb\BinaryOP.hpp"
#include "backends\omp\BinaryOP.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar, typename Left, typename Right>
			void ParallelAdd(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, OMP>::DoOP(left, right, result, [](Scalar x, Scalar y) { return x + y; });
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelMul(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, TBB>::DoOP(left, right, result, [](Scalar x, Scalar y) { return x * y; });
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelSub(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, TBB>::DoOP(left, right, result, [](Scalar x, Scalar y) { return x - y; });
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelDiv(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, TBB>::DoOP(left, right, result, [](Scalar x, Scalar y) { return x / y; });
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelEqual(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, TBB>::DoOP(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x == y); });
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelNotEqual(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, TBB>::DoOP(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x != y); });
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelGreaterThan(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, TBB>::DoOP(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x > y); });
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelLessThan(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, TBB>::DoOP(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x < y); });
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelGraterEqualThan(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, TBB>::DoOP(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x >= y); });
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelLessEqualThan(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, TBB>::DoOP(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x <= y); });
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelMaximum(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, TBB>::DoOP(left, right, result, [](Scalar x, Scalar y) { return std::max(x, y); });
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelMinimum(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, TBB>::DoOP(left, right, result, [](Scalar x, Scalar y) { return std::min(x, y); });
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelPow(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				backend::BinaryOPBackend<Scalar, TBB>::DoOP(left, right, result, [](Scalar x, Scalar y) { return std::pow(x, y); });
			}
		}
	}
}
