#pragma once

#if TML_HAS_TBB
#include <tbb/parallel_for.h>
#include <tbb/parallel_reduce.h>
#include "../../../base/MaxBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct MaxBackend<Scalar, TBB>
				{
					TML_STRONG_INLINE void Max(const tml::Matrix<Scalar>& matrix, Scalar& result)
					{
						std::cout << "running tbb backend" << std::endl;
						typedef typename tml::Matrix<Scalar>::const_iterator iter;
						result = tbb::parallel_reduce(tbb::blocked_range<iter>(matrix.cbegin(), matrix.cend(), 200),
							std::numeric_limits<Scalar>::lowest(),
							[&](const tbb::blocked_range<iter>& range, Scalar currentMax) -> Scalar
						{
							return std::max(currentMax, *std::max_element(range.begin(), range.end()));
						}, [](Scalar left, Scalar right) { return std::max(left, right); });
					}

					TML_STRONG_INLINE void Rows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						std::cout << "running tbb backend" << std::endl;
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						tbb::parallel_for(tbb::blocked_range<size_t>(0, rows, 200), [&](const tbb::blocked_range<size_t>& range)
						{
							for (size_t i = range.begin(); i != range.end(); ++i)
								result[i] = *std::max_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols);
						});
					}

					TML_STRONG_INLINE void Columns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
					{
						std::cout << "running tbb backend" << std::endl;
						size_t rows = matrix.Rows(), cols = matrix.Columns();
						tbb::parallel_for(tbb::blocked_range<size_t>(0, cols, 200), [&](const tbb::blocked_range<size_t>& range)
						{
							for (size_t j = range.begin(); j != range.end(); ++j)
							{
								Scalar colMax = std::numeric_limits<Scalar>::lowest();
								for (size_t i = 0; i < rows; ++i)
									if (matrix[j + i*cols] > colMax)
										colMax = matrix[j + i*cols];
								result[j] = colMax;
							}
						});
					}
				};
			}
		}
	}
}
#endif
