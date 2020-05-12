#pragma once

template<typename Scalar, typename Operand>
struct ReshapeOP
{
	Operand operand;
	ReshapeOP(const Operand& operand) : operand(operand) {}
	void operator++() { ++operand; }
	Scalar operator*() const
	{
		return *operand;
	}
};