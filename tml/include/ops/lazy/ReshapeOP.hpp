#pragma once

template<typename Scalar, typename Operand>
struct ReshapeOP
{
	Operand operand;
	ReshapeOP(const Operand& operand) : operand(operand) {}
	void operator++() { ++operand; }
	Scalar operator[] (size_t index) const { return operand[index]; }
	Scalar operator*() const
	{
		return *operand;
	}
};