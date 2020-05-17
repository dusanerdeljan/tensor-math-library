#include <iostream>
#include "include\tml.hpp"

void TestProfile()
{
	tml::Matrix<double> m1(10000, 10000);
	tml::Matrix<double> m2(10000, 10000);
	tbb::tick_count begin = tbb::tick_count::now();
	tml::Matrix<double> result = tml::eager::SumColumns(m1, tml::SERIAL);
	tbb::tick_count end = tbb::tick_count::now();
	std::cout << "Elapsed tme: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	std::cout << result.GetShape() << std::endl;
	begin = tbb::tick_count::now();
	auto r2 = tml::eager::SumColumns(m1, tml::PARALLEL);
	end = tbb::tick_count::now();
	std::cout << "Elapsed tme: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	std::cout << r2.GetShape() << std::endl;
	//std::cout << result << std::endl;
}

int main()
{
	tml::Matrix<double> m1(7, 10);
	tml::Matrix<double> m2(10, 9);
	std::cout << m1 << std::endl;
	auto sum = tml::eager::MeanColumns(m1);
	std::cout << sum << std::endl;
	//TestProfile();
	std::cout << tml::HardawreConcurrency << std::endl;
	std::cin.get();
	return 0;
}