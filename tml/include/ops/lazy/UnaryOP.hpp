#pragma once

template<typename Scalar, typename Operand, typename OP>
struct UnaryOP
{
	Operand operand;
	UnaryOP(const Operand& operand) : operand(operand) {}
	void operator++() { ++operand; }
	Scalar operator*() const
	{
		return OP::op(*operand);
	}
};
