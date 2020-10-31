#pragma once

#include "../../matrix/Matrix.hpp"

template<typename Scalar, typename T>
struct expr_op
{
	T iter;
	tml::shape shape;
	expr_op(const T& it, tml::shape shape) : iter(it), shape(shape) {}
	Scalar operator*() const { return *iter; }
	Scalar operator[] (size_t index) const { return iter[index]; }
	void operator++() { ++iter; }
	template<typename Dummy>	// g++ workaround
	operator tml::matrix<Scalar>() const
	{
		tml::matrix<Scalar> res = *this;
		return res;
	}
	size_t rows() const { return shape.rows; }
	size_t columns() const { return shape.columns; }
	tml::shape get_shape() const { return shape; }
};