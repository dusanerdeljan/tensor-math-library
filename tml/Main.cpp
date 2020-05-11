#include <iostream>
#include "include\tml.hpp"

int main()
{
	tml::Matrix<int> m1(3, 3);
	tml::Matrix<int> m2(3, 3);
	tml::Matrix<int> res(3, 3);
	res = m1 + 80 + 10 + (m2 + m1) + m2 + 15 + m1;
	std::cout << res << std::endl;
	std::cin.get();
	return 0;
}