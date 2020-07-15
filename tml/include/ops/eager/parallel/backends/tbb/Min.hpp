#pragma once

#if TML_HAS_TBB
#include <tbb/parallel_for.h>
#include <tbb/parallel_reduce.h>
#include "../../../base/MinBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct min_backend<Scalar, TBB>
				{
					TML_STRONG_INLINE void min(const tml::matrix<Scalar>& matrix, Scalar& result)
					{
#undef max
						TML_LOG_BACKEND("tbb");
						typedef typename tml::matrix<Scalar>::const_iterator iter;
						result = tbb::parallel_reduce(tbb::blocked_range<iter>(matrix.cbegin(), matrix.cend(), 200),
							std::numeric_limits<Scalar>::max(),
							[&](const tbb::blocked_range<iter>& range, Scalar currentMin) -> Scalar
						{
							return std::min<Scalar>(currentMin, *std::min_element(range.begin(), range.end()));
						}, [](Scalar left, Scalar right) { return std::min<Scalar>(left, right); });
					}

					TML_STRONG_INLINE void rows(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("tbb");
						size_t rows = matrix.rows(), cols = matrix.columns();
						tbb::parallel_for(tbb::blocked_range<size_t>(0, rows, 200), [&](const tbb::blocked_range<size_t>& range)
						{
							for (size_t i = range.begin(); i != range.end(); ++i)
								result[i] = *std::min_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols);
						});
					}

					TML_STRONG_INLINE void columns(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("tbb");
						size_t rows = matrix.rows(), cols = matrix.columns();
						tbb::parallel_for(tbb::blocked_range<size_t>(0, cols, 200), [&](const tbb::blocked_range<size_t>& range)
						{
							for (size_t j = range.begin(); j != range.end(); ++j)
							{
								Scalar colMin = std::numeric_limits<Scalar>::max();
								for (size_t i = 0; i < rows; ++i)
									if (matrix[j + i*cols] < colMin)
										colMin = matrix[j + i*cols];
								result[j] = colMin;
							}
						});
					}
				};
			}
		}
	}
}
#endif
