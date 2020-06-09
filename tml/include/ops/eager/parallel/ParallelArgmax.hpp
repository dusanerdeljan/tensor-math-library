#pragma once

#undef max

#include <algorithm>
#include <limits>
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
			void ParallelArgmaxAll(const tml::Matrix<Scalar>& matrix, Scalar& result)
			{
#if TML_HAS_TBB
				typedef typename tml::Matrix<Scalar>::const_iterator iter;
				auto res = tbb::parallel_reduce(tbb::blocked_range<iter>(matrix.cbegin(), matrix.cend(), 200),
					matrix.cbegin(),
					[](const tbb::blocked_range<iter>& range, const iter& currentMin) -> iter
				{
					iter rangeMin = std::max_element(range.begin(), range.end());
					return *currentMin >= *rangeMin ? currentMin : rangeMin;
				}, [](const iter& left, const iter& right) { return std::max<iter>(left, right, [](const iter& l, const iter& r) { return *l >= *r; }); }) - matrix.cbegin();
				result = static_cast<Scalar>(res);
#endif
			}

			template<typename Scalar>
			void ParallelArgmaxRows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
#if TML_HAS_TBB
				size_t cols = matrix.Columns();
				tbb::parallel_for(tbb::blocked_range<size_t>(0, matrix.Rows(), 100), [&](const tbb::blocked_range<size_t>& range)
				{
					for (size_t i = range.begin(); i != range.end(); ++i)
						result[i] = static_cast<Scalar>(std::max_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols) - (matrix.cbegin() + i*cols));
				});
#endif
			}

			template<typename Scalar>
			void ParallelArgmaxColumns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
#if TML_HAS_TBB
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				const tml::Matrix<Scalar> transposed = tml::eager::Transpose(matrix, tml::PARALLEL);
				tbb::parallel_for(tbb::blocked_range<size_t>(0, cols, 200), [&](const tbb::blocked_range<size_t>& range)
				{
					for (size_t i = range.begin(); i != range.end(); ++i)
						result[i] = static_cast<Scalar>(std::max_element(transposed.cbegin() + i*rows, transposed.cbegin() + (i + 1)*rows) - (transposed.cbegin() + i*rows));
				});
#endif
			}
		}
	}
}