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
	std::vector<double> mat = { 1, 2, 3, 4, 5, 6 };
	tml::Matrix<double> m1(&mat[0], {3, 2}, tml::VIEW);
	mat[3] = 99;
	std::cout << m1 << std::endl;
	std::cout << "=================" << std::endl;
	for (auto x : mat)
		std::cout << x << " ";
	std::cout << std::endl;
	//TestProfile();
	std::cout << tml::HardawreConcurrency << std::endl;
	std::cin.get();
	return 0;
}