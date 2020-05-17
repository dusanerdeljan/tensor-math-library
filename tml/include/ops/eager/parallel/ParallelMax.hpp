#pragma once

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
			void ParallelMaxAll(const tml::Matrix<Scalar>& matrix, Scalar& result)
			{
				typedef typename tml::Matrix<Scalar>::const_iterator iter;
				result = tbb::parallel_reduce(tbb::blocked_range<iter>(matrix.cbegin(), matrix.cend(), 200),
					std::numeric_limits<Scalar>::lowest(),
					[&](const tbb::blocked_range<iter>& range, Scalar currentMax) -> Scalar
				{
					return std::max(currentMax, *std::max_element(range.begin(), range.end()));
				}, [](Scalar left, Scalar right) { return std::max(left, right); });
			}

			template<typename Scalar>
			void ParallelMaxRows(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t cols = matrix.Columns();
				tbb::parallel_for(tbb::blocked_range<size_t>(0, matrix.Rows(), 100), [&](const tbb::blocked_range<size_t>& range)
				{
					for (size_t i = range.begin(); i != range.end(); ++i)
						result[i] = *std::max_element(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols);
				});
			}

			template<typename Scalar>
			void ParallelMaxColumns(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result)
			{
				size_t rows = matrix.Rows(), cols = matrix.Columns();
				const tml::Matrix<Scalar> transposed = tml::eager::Transpose(matrix, tml::PARALLEL);
				tbb::parallel_for(tbb::blocked_range<size_t>(0, cols, 200), [&](const tbb::blocked_range<size_t>& range)
				{
					for (size_t i = range.begin(); i != range.end(); ++i)
						result[i] = *std::max_element(transposed.cbegin() + i*rows, transposed.cbegin() + (i + 1)*rows);
				});
			}
		}
	}
}