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

		friend std::ostream& operator << (std::ostream& out, const tml::Shape& shape)
		{
			return out << "( " << shape.Rows << ", " << shape.Columns << " )";
		}
	};
}