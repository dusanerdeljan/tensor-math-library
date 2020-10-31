#pragma once

#if TML_HAS_TBB
#include <numeric>
#include <tbb/parallel_for.h>
#include <tbb/parallel_reduce.h>
#include "../../../base/MeanBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct mean_backend<Scalar, TBB>
				{
					TML_STRONG_INLINE void mean(const tml::matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("tbb");
						typedef typename tml::matrix<Scalar>::const_iterator iter;
						result = static_cast<Scalar>(tbb::parallel_reduce(tbb::blocked_range<iter>(matrix.cbegin(), matrix.cend(), 200),
							static_cast<Scalar>(0),
							[&](const tbb::blocked_range<iter>& range, Scalar sum) -> Scalar
						{
							return TML_ACCUMULATE(range.begin(), range.end(), sum);
						}, std::plus<Scalar>()) / matrix.size());
					}

					TML_STRONG_INLINE void rows(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("tbb");
						size_t cols = matrix.columns();
						tbb::parallel_for(tbb::blocked_range<size_t>(0, matrix.rows(), 100), [&](const tbb::blocked_range<size_t>& range)
						{
							for (size_t i = range.begin(); i != range.end(); ++i)
								result[i] = static_cast<Scalar>(TML_ACCUMULATE(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols, static_cast<Scalar>(0)) / cols);
						});
					}

					TML_STRONG_INLINE void columns(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("tbb");
						size_t rows = matrix.rows(), cols = matrix.columns();
						tbb::parallel_for(tbb::blocked_range<size_t>(0, cols, 100), [&](const tbb::blocked_range<size_t>& range)
						{
							for (size_t j = range.begin(); j != range.end(); ++j)
							{
								Scalar colMean = static_cast<Scalar>(0);
								for (size_t i = 0; i < rows; ++i)
									colMean += matrix[j + i*cols];
								result[j] = static_cast<Scalar>(colMean / rows);
							}
						});
					}
				};
			}
		}
	}
}
#endif
