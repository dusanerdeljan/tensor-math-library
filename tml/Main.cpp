#include <iostream>
#include "include\tml.hpp"

int main()
{
	tml::Matrix<double> m1(5, 5);
	std::cout << m1 << std::endl;

	tml::Matrix<int> m2(3, 3);
	std::cout << m2 << std::endl;
	std::cin.get();
	return 0;
}