#pragma once

#include "..\..\matrix\Matrix.hpp"

template<typename Scalar, typename T>
struct ExprOP
{
	T iter;
	ExprOP(const T& it) : iter(it) {}
	Scalar operator*() const { return *iter; }
	void operator++() { ++iter; }
};