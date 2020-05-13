#pragma once

template<typename Scalar, typename Operand, typename OP>
struct UnaryOP
{
	Operand operand;
	UnaryOP(const Operand& operand) : operand(operand) {}
	void operator++() { ++operand; }
	Scalar operator[] (size_t index) const { return OP::op(operand[index]); }
	Scalar operator*() const
	{
		return OP::op(*operand);
	}
};
