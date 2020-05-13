#pragma once

template<typename Scalar, typename Left, typename Right, typename OP>
struct BinaryOP
{
	Left left;
	Right right;
	BinaryOP(const Left& left, const Right& right) : left(left), right(right) {}
	void operator++() { ++left; ++right; }
	Scalar operator[] (size_t index) const { return OP::op(left[index], right[index]); }
	Scalar operator*() const
	{
		return OP::op(*left, *right);
	}
};
