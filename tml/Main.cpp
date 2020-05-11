#include <iostream>
#include "include\tml.hpp"

namespace tmll = tml::lazy;

int main()
{
	tml::Matrix<double> m1(3, 3);
	tml::Matrix<double> m2(3, 3);
	tml::Matrix<double> res = tmll::Abs(-tmll::Square(-(m1 + 10.0)));
	std::cout << res << std::endl;
	std::cin.get();
	return 0;
}