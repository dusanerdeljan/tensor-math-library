#include <iostream>
#include "include\tml.hpp"

namespace tmll = tml::lazy;

void foo(const tml::Matrix<double>& matrix)
{
	std::cout << matrix << std::endl;
}

int main()
{
	tml::Matrix<double> m1(3, 3);
	tml::Matrix<double> m2(3, 3);
	tml::Matrix<double> result = tmll::Pow(m1, 2.0*m2);
	std::cout << result << std::endl;
	std::cin.get();
	return 0;
}