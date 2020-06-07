#include <iostream>
#include "include\tml.hpp"

void TestProfile()
{
	tml::Matrix<int> m1(10000, 10000);
	//tml::Matrix<int> m2(10000, 10000);
	tbb::tick_count begin = tbb::tick_count::now();
	auto result = tml::eager::Log(m1, tml::SERIAL);
	tbb::tick_count end = tbb::tick_count::now();
	std::cout << "Elapsed time: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	std::cout << result.GetShape() << std::endl;
	begin = tbb::tick_count::now();
	auto r2 = tml::eager::Log(m1, tml::PARALLEL);
	end = tbb::tick_count::now();
	std::cout << "Elapsed time: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	std::cout << r2.GetShape() << std::endl;
	//std::cout << result << std::endl;
}

int main()
{
	TestProfile();
	std::cin.get();
	return 0;
}