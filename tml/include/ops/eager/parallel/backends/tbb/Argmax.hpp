#pragma once

#if TML_HAS_TBB
#undef max
#include <tbb/parallel_for.h>
#include <tbb/parallel_reduce.h>
#include "../../../base/ArgmaxBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct argmax_backend<Scalar, TBB>
				{
					TML_STRONG_INLINE void argmax(const tml::matrix<Scalar>& matrix, Scalar& result)
					{
						TML_LOG_BACKEND("tbb");
						typedef typename tml::matrix<Scalar>::const_iterator iter;
						auto res = tbb::parallel_reduce(tbb::blocked_range<iter>(matrix.cbegin(), matrix.cend(), 200),
							matrix.cbegin(),
							[](const tbb::blocked_range<iter>& range, const iter& currentMax) -> iter
						{
							iter rangeMax = std::max_element(range.begin(), range.end());
							return *currentMax >= *rangeMax ? currentMax : rangeMax;
						}, [](const iter& left, const iter& right) { return *left >= *right ? left : right; }) - matrix.cbegin();
						result = static_cast<Scalar>(res);
					}

					TML_STRONG_INLINE void rows(const tml::matrix<Scalar>& matrix, tml::matrix<Scalar>& result)
					{
						TML_LOG_BACKEND("tbb");
						size_t rows = matrix.rows(), cols = matrix.columns();
						tbb::parallel_for(tbb::blocked_range<size_t>(0, rows, 200), [&](const tbb::blocked_range<size_t>& range)
						{
							for (size_t i = range.begin(); i != range.end(); ++i)
								result[i] = static_cast<Scalar>(std::max_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols) - (matrix.cbegin() + i*cols));
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
								size_t colArgmax = 0;
								for (size_t i = 0; i < rows; ++i)
									if (matrix[j + i*cols] > matrix[j + colArgmax*cols])
										colArgmax = i;
								result[j] = static_cast<Scalar>(colArgmax);
							}
						});
					}
				};
			}
		}
	}
}
#endif
