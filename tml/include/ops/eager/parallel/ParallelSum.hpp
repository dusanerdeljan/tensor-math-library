#pragma once

#include <numeric>
#if TML_HAS_TBB
#include <tbb/parallel_for.h>
#include <tbb/parallel_reduce.h>
#endif
#include "../../../matrix/Matrix.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar>
			void ParallelSumAll(const tml::Matrix<Scalar>& matrix, Scalar& result)
			{
#if TML_HAS_TBB
				typedef typename tml::Matrix<Scalar>::const_iterator iter;
				result = tbb::parallel_deterministic_reduce(tbb::blocked_range<iter>(matrix.cbegin(), matrix.cend(), 200),
					static_cast<Scalar>(0),
					[&](const tbb::blocked_range<iter>& range, Scalar sum) -> Scalar
				{
					return std::accumulate(range.begin(), range.end(), sum);
				}, std::plus<Scalar>());
#endif // TML_HAS_TBB
			}

			template<typename Scalar>
			void ParallelSumRows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
#if TML_HAS_TBB
				size_t cols = matrix.Columns();
				tbb::parallel_for(tbb::blocked_range<size_t>(0, matrix.Rows(), 100), [&](const tbb::blocked_range<size_t>& range)
				{
					for (size_t i = range.begin(); i != range.end(); ++i)
						result[i] = std::accumulate(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols, static_cast<Scalar>(0));
				});
#endif
			}

			template<typename Scalar>
			void ParallelSumColumns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
#if TML_HAS_TBB
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				const tml::Matrix<Scalar> transposed = tml::eager::Transpose(matrix, tml::PARALLEL);
				tbb::parallel_for(tbb::blocked_range<size_t>(0, cols, 200), [&](const tbb::blocked_range<size_t>& range)
				{
					for (size_t i = range.begin(); i != range.end(); ++i)
						result[i] = std::accumulate(transposed.cbegin() + i*rows, transposed.cbegin() + (i + 1)*rows, static_cast<Scalar>(0));
				});
#endif
			}
		}
	}
}
