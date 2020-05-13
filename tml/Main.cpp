#include <iostream>
#include "include\tml.hpp"

void TestProfile()
{
	tml::Matrix<double> m1(5000, 5000);
	tml::Matrix<double> m2(5000, 5000);
	tbb::tick_count begin = tbb::tick_count::now();
	tml::Matrix<double> result = tml::eager::Tanh(m1);
	tbb::tick_count end = tbb::tick_count::now();
	std::cout << "Elapsed tme: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	begin = tbb::tick_count::now();
	result = tml::eager::Tanh(m1, tml::PARALLEL, tml::PARALLEL_FOR);
	end = tbb::tick_count::now();
	std::cout << "Elapsed tme: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	//std::cout << result << std::endl;
}

int main()
{
	tml::Matrix<double> m1(4, 4);
	tml::Matrix<double> m2(4, 4);
	/*auto result = tml::eager::CustomUnaryOP(m1, [](double x) { return 5 * x; }, tml::PARALLEL, tml::PARALLEL_FOR);
	std::cout << result << std::endl;*/
	TestProfile();
	std::cout << tml::HardawreConcurrency << std::endl;
	std::cin.get();
	return 0;
}