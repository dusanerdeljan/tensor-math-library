#pragma once

#include "backends\tbb\TBBBackend.hpp"
#include "backends\omp\OMPBackend.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar, typename Left, typename Right>
			void ParallelAdd(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return x + y; }, parallelism);
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelMul(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return x * y; }, parallelism);
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelSub(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return x - y; }, parallelism);
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelDiv(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return x / y; }, parallelism);
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelEqual(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x == y); }, parallelism);
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelNotEqual(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x != y); }, parallelism);
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelGreaterThan(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x > y); }, parallelism);
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelLessThan(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x < y); }, parallelism);
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelGraterEqualThan(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x >= y); }, parallelism);
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelLessEqualThan(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return static_cast<Scalar>(x <= y); }, parallelism);
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelMaximum(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return std::max(x, y); }, parallelism);
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelMinimum(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return std::min(x, y); }, parallelism);
			}

			template<typename Scalar, typename Left, typename Right>
			void ParallelPow(const Left& left, const Right& right, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
			{
				tbbbackend::ParallelCustomBinaryOP(left, right, result, [](Scalar x, Scalar y) { return std::pow(x, y); }, parallelism);
			}
		}
	}
}
