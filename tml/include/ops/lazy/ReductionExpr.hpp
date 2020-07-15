#pragma once

template<typename Scalar, typename Operand, typename OP>
struct reduction_expr
{
	const Operand& operand;
	size_t row = 0;
	reduction_expr(const Operand& operand) : operand(operand) {}
	void operator++() { ++row; }
	Scalar operator[] (size_t index) const { return OP::op(operand, index); }
	Scalar operator*() const
	{
		return OP::op(operand, row);
	}
};
