#include <iostream>
#include "include\tml.hpp"

int main()
{
	tml::Matrix<int> m1(3, 3);
	tml::Matrix<int> m2(3, 3);
	tml::Matrix<int> res = m1 - (m1 + m2) + (m2 + m2) - m1 + 15;
	std::cout << res << std::endl;
	std::cin.get();
	return 0;
}