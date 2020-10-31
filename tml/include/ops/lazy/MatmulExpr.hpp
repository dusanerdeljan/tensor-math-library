#pragma once

template<typename Scalar, typename Left, typename Right>
struct MatmulExpr
{
	const Left& left;
	const Right& right;
	size_t idx = 0;
	MatmulExpr(const Left& left, const Right& right) : left(left), right(right) {}
	void operator++() { ++idx; }
	Scalar operator*() const { return (*this)[idx]; }
	Scalar operator[] (size_t index) const
	{
		size_t row = index / right.columns();
		size_t col = index - row * right.columns();
		Scalar sum = static_cast<Scalar>(0);
		for (size_t i = 0; i < left.columns(); ++i)
			sum += left[i + row*left.columns()] * right[col + i*right.columns()];
		return sum;
	}
};
