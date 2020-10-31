#pragma once

template<typename Scalar>
struct scalar_expr
{
	Scalar scalar;
	scalar_expr(Scalar scalar) : scalar(scalar) {}
	void operator++() {}
	Scalar operator[] (size_t index) const { return scalar; }
	Scalar operator*() const { return scalar; }
};
