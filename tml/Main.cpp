#include <iostream>
#include "include\tml.hpp"

int main()
{
	tml::Matrix<double> m1(3, 3);
	tml::Matrix<double> m2(3, 3);
	tml::Matrix<double> res = tml::lazy::Square(m1 + m2) - 10.0 + tml::lazy::Log(16.0);
	std::cout << res << std::endl;
	std::cin.get();
	return 0;
}