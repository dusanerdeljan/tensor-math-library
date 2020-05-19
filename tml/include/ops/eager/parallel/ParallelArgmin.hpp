#pragma once

#undef max

#include <algorithm>
#include <limits>
#include <tbb\parallel_for.h>
#include <tbb\parallel_reduce.h>
#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar>
			void ParallelArgminAll(const tml::Matrix<Scalar>& matrix, Scalar& result)
			{
				typedef typename tml::Matrix<Scalar>::const_iterator iter;
				auto res = tbb::parallel_reduce(tbb::blocked_range<iter>(matrix.cbegin(), matrix.cend(), 200),
					matrix.cbegin(),
					[](const tbb::blocked_range<iter>& range, const iter& currentMin) -> iter
				{
					iter rangeMin = std::min_element(range.begin(), range.end());
					return *currentMin <= *rangeMin ? currentMin : rangeMin;
				}, [](const iter& left, const iter& right) { return std::min<iter>(left, right, [](const iter& l, const iter& r) { return *l < *r; }); }) - matrix.cbegin();
				result = static_cast<Scalar>(res);
			}

			template<typename Scalar>
			void ParallelArgminRows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t cols = matrix.Columns();
				tbb::parallel_for(tbb::blocked_range<size_t>(0, matrix.Rows(), 100), [&](const tbb::blocked_range<size_t>& range)
				{
					for (size_t i = range.begin(); i != range.end(); ++i)
						result[i] = std::min_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols) - (matrix.cbegin() + i*cols);
				});
			}

			template<typename Scalar>
			void ParallelArgminColumns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				const tml::Matrix<Scalar> transposed = tml::eager::Transpose(matrix, tml::PARALLEL);
				tbb::parallel_for(tbb::blocked_range<size_t>(0, cols, 200), [&](const tbb::blocked_range<size_t>& range)
				{
					for (size_t i = range.begin(); i != range.end(); ++i)
						result[i] = std::min_element(transposed.cbegin() + i*rows, transposed.cbegin() + (i + 1)*rows) - (transposed.cbegin() + i*rows);
				});
			}
		}
	}
}