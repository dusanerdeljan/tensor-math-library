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
		size_t row = index / right.Columns();
		size_t col = index - row * right.Columns();
		Scalar sum = static_cast<Scalar>(0);
		for (size_t i = 0; i < left.Columns(); ++i)
			sum += left[i + row*left.Columns()] * right[col + i*right.Columns()];
		return sum;
	}
};
