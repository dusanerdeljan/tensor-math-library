#pragma once

template<typename Scalar>
struct ScalarExpr
{
	Scalar scalar;
	ScalarExpr(Scalar scalar) : scalar(scalar) {}
	void operator++() {}
	Scalar operator[] (size_t index) const { return scalar; }
	Scalar operator*() const { return scalar; }
};
