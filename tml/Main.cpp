#include <iostream>
#include "include\tml.hpp"

namespace tmll = tml::lazy;

void foo(const tml::Matrix<double>& matrix)
{
	std::cout << matrix << std::endl;
}

int main()
{
	tml::Matrix<int> m1(3, 3);
	tml::Matrix<double> m2 = tml::Matrix<double>::OnesLike(m1);
	std::cout << m2 << std::endl;
	std::cin.get();
	return 0;
}