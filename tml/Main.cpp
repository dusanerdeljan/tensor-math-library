#include <iostream>
#include "include\tml.hpp"

void TestProfile()
{
	tml::Matrix<double> m1(5000, 5000);
	tml::Matrix<double> m2(5000, 5000);
	tbb::tick_count begin = tbb::tick_count::now();
	tml::Matrix<double> result = tml::eager::Transpose(m1);
	tbb::tick_count end = tbb::tick_count::now();
	std::cout << "Elapsed tme: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	begin = tbb::tick_count::now();
	result = tml::eager::Transpose(m1, tml::PARALLEL);
	end = tbb::tick_count::now();
	std::cout << "Elapsed tme: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	//std::cout << result << std::endl;
}

int main()
{
	tml::Matrix<double> matrix(3, 8);
	std::cout << matrix << std::endl;
	tml::Matrix<double> res = tml::lazy::Transpose(matrix);
	std::cout << res << std::endl;
	tml::Matrix<double> result = tml::eager::Mul(matrix, matrix, tml::PARALLEL);
	std::cout << result << std::endl;
	//TestProfile();
	std::cout << tml::HardawreConcurrency << std::endl;
	std::cin.get();
	return 0;
}