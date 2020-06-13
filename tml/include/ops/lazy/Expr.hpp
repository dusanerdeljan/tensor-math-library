#pragma once

#include "../../matrix/Matrix.hpp"

template<typename Scalar, typename T>
struct ExprOP
{
	T iter;
	tml::Shape shape;
	ExprOP(const T& it, tml::Shape shape) : iter(it), shape(shape) {}
	Scalar operator*() const { return *iter; }
	Scalar operator[] (size_t index) const { return iter[index]; }
	void operator++() { ++iter; }
	template<typename Dummy>	// g++ workaround
	operator tml::Matrix<Scalar>() const
	{
		tml::Matrix<Scalar> res = *this;
		return res;
	}
	size_t Rows() const { return shape.Rows; }
	size_t Columns() const { return shape.Columns; }
	tml::Shape GetShape() const { return shape; }
};