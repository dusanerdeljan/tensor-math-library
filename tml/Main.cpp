#include <iostream>
#include <chrono>
#include "include/tml.hpp"

void test_profile()
{
	tml::matrix<int> m1(1000, 1000);
	tml::matrix<int> m2(1000, 1000);
	auto t1 = std::chrono::high_resolution_clock::now();
	auto result = tml::eager::matmul(m1, m2, tml::execution::omp);
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms." << std::endl;
	std::cout << result.get_shape() << std::endl;
	t1 = std::chrono::high_resolution_clock::now();
	auto result2 = tml::eager::matmul(m1, m2, tml::execution::stl);
	t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms." << std::endl;
	std::cout << result2.get_shape() << std::endl;
	tml::matrix<int> valid = result == result2;
	std::cout << "Valid: " << std::all_of(valid.begin(), valid.end(), [](int x) {return x > 0;}) << std::endl;
	//std::cout << result << std::endl;
}

int main()
{
	test_profile();
	tml::matrix<int64_t> m1 = tml::matrix<int>::arange(4, 6);
	tml::matrix<int> m2 = tml::matrix<int>::arange(4, 4);
	tml::matrix<int> m3 = tml::matrix<int>::arange(4, 4);
	std::cout << m1 << std::endl;
	std::cout << tml::eager::exp(m1, tml::execution::omp) << std::endl;
	std::cout << (tml::matrix<int64_t>)tml::lazy::abs(m1) << std::endl;
	std::cout << tml::eager::greater_equal_than(m2, m3, tml::execution::omp) << std::endl;
	std::cin.get();
	return 0;
}
