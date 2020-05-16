#include <iostream>
#include "include\tml.hpp"

void TestProfile()
{
	tml::Matrix<double> m1(1000, 1000);
	tml::Matrix<double> m2(1000, 1000);
	tbb::tick_count begin = tbb::tick_count::now();
	tml::Matrix<double> result = tml::eager::Matmul(m1, m2);
	tbb::tick_count end = tbb::tick_count::now();
	std::cout << "Elapsed tme: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	begin = tbb::tick_count::now();
	result = tml::eager::Matmul(m1, m2, tml::PARALLEL, tml::ONE_OVER_CORES);
	end = tbb::tick_count::now();
	std::cout << "Elapsed tme: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	//std::cout << result << std::endl;
}

int main()
{
	tml::Matrix<double> m1(7, 10);
	tml::Matrix<double> m2(10, 9);
	tml::Matrix<double> result = tml::eager::Matmul(m1, m2, tml::PARALLEL, tml::SINGLE_ROW);
	std::cout << result << std::endl;
	TestProfile();
	std::cout << tml::HardawreConcurrency << std::endl;
	std::cin.get();
	return 0;
}