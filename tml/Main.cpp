#include <iostream>
#include <chrono>
#include "include/tml.hpp"

/*!
* TODOS:
*
* 1. Multi-backend for and reduction ops
*
*/

void TestProfile()
{
	tml::Matrix<int> m1(10000, 10000);
	tml::Matrix<int> m2(10000, 10000);
	auto t1 = std::chrono::high_resolution_clock::now();
	auto result = tml::eager::Min(m1, tml::execution::omp);
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms." << std::endl;
	std::cout << result << std::endl;
	t1 = std::chrono::high_resolution_clock::now();
	auto r2 = tml::eager::Min(m2, tml::execution::tbb);
	t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms." << std::endl;
	std::cout << result << std::endl;
	//std::cout << result << std::endl;
}

int main()
{
	TestProfile();
	tml::Matrix<double> m1 = tml::Matrix<double>::Arange(4, 6);
	tml::Matrix<int> m2 = tml::Matrix<int>::Arange(4, 4);
	tml::Matrix<int> m3 = tml::Matrix<int>::Arange(4, 4);
	std::cout << m1 << std::endl;
	std::cout << tml::eager::Min(m1, tml::execution::omp) << std::endl;
	std::cout << tml::eager::MinRows(m1, tml::execution::omp) << std::endl;
	std::cout << tml::eager::MinColumns(m1, tml::execution::omp) << std::endl;
	std::cin.get();
	return 0;
}
