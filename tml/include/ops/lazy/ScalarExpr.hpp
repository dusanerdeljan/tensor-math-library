#pragma once

template<typename Scalar>
struct ScalarExpr
{
	Scalar scalar;
	ScalarExpr(Scalar scalar) : scalar(scalar) {}
	void operator++() {}
	Scalar operator*() const { return scalar; }
};
