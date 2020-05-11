#pragma once

#include "..\..\matrix\Matrix.hpp"

template<typename Scalar, typename T>
struct ExprOP
{
	T iter;
	tml::Shape shape;
	ExprOP(const T& it, tml::Shape shape) : iter(it), shape(shape) {}
	Scalar operator*() const { return *iter; }
	void operator++() { ++iter; }
};