#pragma once

template<typename Scalar, typename Operand, typename OP>
struct ReductionExpr
{
	const Operand& operand;
	size_t row = 0;
	ReductionExpr(const Operand& operand) : operand(operand) {}
	void operator++() { ++row; }
	Scalar operator[] (size_t index) const { return OP::op(operand, index); }
	Scalar operator*() const
	{
		return OP::op(operand, row);
	}
};
