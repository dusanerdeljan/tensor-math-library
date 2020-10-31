#pragma once

template<typename Scalar, typename Operand>
struct transpose_expr
{
	Operand operand;
	size_t rows;
	size_t cols;
	size_t idx = 0;
	transpose_expr(const Operand& operand, size_t rows, size_t cols) : operand(operand), rows(rows), cols(cols) {}
	void operator++() { ++idx; }
	Scalar operator[] (size_t index) const
	{
		const size_t row = index / rows;
		const size_t col = index - row*rows;
		return operand[row + col*cols];
	}
	Scalar operator*() const
	{
		// TODO: Maybe rework this later
		const size_t row = idx / rows;
		const size_t col = idx - row*rows;
		return operand[row + col*cols];
	}
};
