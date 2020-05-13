#include <iostream>
#include "include\tml.hpp"

template<typename Scalar, typename T>
void foo(const ExprOP<Scalar, T>& expr)
{
	tml::Matrix<Scalar> matrix = expr;
	std::cout << matrix << std::endl;
}

int main()
{
	tml::Matrix<double> m1(4, 4);
	tml::Matrix<double> m2(4, 4);
	auto result = tml::eager::Maximum(m1*2.0, 10.0);
	std::cout << result << std::endl;
	std::cout << tml::HardawreConcurrency << std::endl;
	std::cin.get();
	return 0;
}