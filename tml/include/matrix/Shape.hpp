#pragma once
#include <iostream>

namespace tml
{
	struct shape
	{
		size_t rows;
		size_t columns;
		size_t size;

		shape(size_t rows, size_t cols) : rows(rows), columns(cols), size(rows*cols) {}

		shape transpose() const
		{
			return{ columns, rows };
		}

		bool operator==(const shape& rhs) { return ((rows == rhs.rows) && (columns == rhs.columns)); }

		bool operator != (const shape& rhs) { return !(*this == rhs); }

		friend std::ostream& operator << (std::ostream& out, const tml::shape& shape)
		{
			return out << "( " << shape.rows << ", " << shape.columns << " )";
		}
	};
}