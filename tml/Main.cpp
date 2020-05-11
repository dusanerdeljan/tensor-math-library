#include <iostream>
#include "include\tml.hpp"

namespace tmll = tml::lazy;

int main()
{
	tml::Matrix<double> m1(3, 3);
	tml::Matrix<double> m2(3, 3);
	tml::Matrix<double> res = tmll::Cosh(m1 + m2 + 1.0) - 10.0 + tmll::Log(16.0);
	std::cout << res << std::endl;
	std::cin.get();
	return 0;
}