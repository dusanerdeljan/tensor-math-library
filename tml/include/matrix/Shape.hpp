#pragma once
#include <iostream>

namespace tml
{
	struct Shape
	{
		size_t Rows;
		size_t Columns;
		size_t Size;

		Shape(size_t rows, size_t cols) : Rows(rows), Columns(cols), Size(rows*cols) {}

		Shape Transpose() const
		{
			return{ Columns, Rows };
		}

		bool operator==(const Shape& rhs) { return ((Rows == rhs.Rows) && (Columns == rhs.Columns)); }

		bool operator != (const Shape& rhs) { return !(*this == rhs); }

		friend std::ostream& operator << (std::ostream& out, const tml::Shape& shape)
		{
			return out << "( " << shape.Rows << ", " << shape.Columns << " )";
		}
	};
}