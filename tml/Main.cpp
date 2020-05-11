#include <iostream>
#include "include\tml.hpp"

int main()
{
	tml::Matrix<double> m1(3, 3);
	tml::Matrix<double> m2(3, 3);
	m2 = m1 + 1.0;
	tml::Matrix<> temp = tml::lazy::Log(m2);
	tml::Matrix<> res = m1 + tml::lazy::Log(m1 + 1.0);
	std::cout << res << std::endl;
	std::cin.get();
	return 0;
}