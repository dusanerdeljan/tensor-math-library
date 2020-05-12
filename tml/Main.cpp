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
	tml::Matrix<double> result = tml::lazy::CustomOP(3.0*m1, 5.0*m2, [](double x, double y) { return x + y; });
	tml::Matrix<double> res = 3.0*m1 + m2*5.0;
	std::cout << result << std::endl;
	std::cout << res << std::endl;
	std::cin.get();
	return 0;
}