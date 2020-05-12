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
	tml::Matrix<double> result = 10.0 + tml::lazy::Div(m1, m2+1.0);
	std::cout << result << std::endl;
	std::cin.get();
	return 0;
}