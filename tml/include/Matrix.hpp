#pragma once

#include <iostream>
#include <iomanip>

#include "Shape.hpp"

template<typename Scalar>
class Matrix
{
private:
	Scalar* m_Data;
	Shape m_Shape;
public:
	typedef Scalar* iterator;
	typedef const Scalar* const_iterator;
	Matrix(size_t rows, size_t cols) : m_Data(new Scalar[rows*cols]), m_Shape(rows, cols)
	{
		for (size_t i = 0; i < m_Shape.Size; ++i) m_Data[i] = i;
	}
	~Matrix() { delete[] m_Data; }

	inline Scalar& operator() (size_t i, size_t j) { return m_Data[j + i*m_Shape.Columns]; }
	inline const Scalar& operator() (size_t i, size_t j) const { return m_Data[j + i*m_Shape.Columns]; }

	inline iterator begin() { return m_Data; }

	inline const_iterator cbegin() const { return m_Data; }

	inline iterator end() { return m_Data + m_Rows*m_Cols; }

	inline const_iterator cend() const { return m_Data + m_Rows*m_Cols; }

	inline size_t Size() const { return m_Shape.Size; }

	inline size_t Rows() const { return m_Shape.Rows; }

	inline size_t Columns() const { return m_Shape.Columns; }

	friend std::ostream& operator << (std::ostream& out, const Matrix<Scalar>& matrix)
	{
		for (size_t i = 0; i < matrix.Rows(); ++i)
		{
			for (size_t j = 0; j < matrix.Columns(); ++j)
				std::cout << std::setw(6) << std::left << matrix(i, j);
			std::cout << std::endl;
		}
		return out;
	}

};
