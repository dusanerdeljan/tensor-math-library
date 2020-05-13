#include <iostream>
#include "include\tml.hpp"

void TestProfile()
{
	tml::Matrix<double> m1(5000, 5000);
	tml::Matrix<double> m2(5000, 5000);
	tbb::tick_count begin = tbb::tick_count::now();
	tml::Matrix<double> result = m1 + m2 + tml::lazy::Log(m1 + 5.0*m2) + tml::lazy::Sqrt(m2);
	tbb::tick_count end = tbb::tick_count::now();
	std::cout << "Elapsed tme: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	begin = tbb::tick_count::now();
	result = tml::eager::Add(tml::eager::Add(m1, m2), tml::eager::Add(tml::eager::Log(tml::eager::Add(m2, tml::eager::Mul(5.0, m2))), tml::eager::Sqrt(m2)));
	end = tbb::tick_count::now();
	std::cout << "Elapsed tme: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	//std::cout << result << std::endl;
}

int main()
{
	tml::Matrix<double> m1(4, 4);
	tml::Matrix<double> m2(4, 4);
	auto result = tml::eager::CustomUnaryOP(m1, [](double x) { return 5 * x; }, tml::PARALLEL, tml::PARALLEL_FOR);
	std::cout << result << std::endl;
	std::cout << tml::HardawreConcurrency << std::endl;
	std::cin.get();
	return 0;
}