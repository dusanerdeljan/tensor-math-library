#pragma once

template<typename Scalar, typename Operand>
struct reshape_op
{
	Operand operand;
	reshape_op(const Operand& operand) : operand(operand) {}
	void operator++() { ++operand; }
	Scalar operator[] (size_t index) const { return operand[index]; }
	Scalar operator*() const
	{
		return *operand;
	}
};