#include <iostream>
#include "include\tml.hpp"

int main()
{
	tml::Matrix<double> m1(3, 3);
	tml::Matrix<double> m2(3, 3);
	tml::Matrix<double> res = tml::lazy::Sqrt(m1*m1);
	std::cout << res << std::endl;
	std::cin.get();
	return 0;
}