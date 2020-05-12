#include <iostream>
#include "include\tml.hpp"

void foo(const tml::Matrix<double>& matrix)
{
	std::cout << matrix << std::endl;
}

int main()
{
	tml::Matrix<double> m1(4, 4);
	tml::Matrix<double> m2(4, 4);
	tml::Matrix<double> result = tml::lazy::Reshape(m1+15.0, { 2, 8 });
	std::cout << result << std::endl;
	std::cin.get();
	return 0;
}