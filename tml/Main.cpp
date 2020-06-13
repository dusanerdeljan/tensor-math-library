#include <iostream>
#include <chrono>
#include "include/tml.hpp"

/*!
* TODOS:
*
* 1. C++ 17 parallel stl for reduction ops
*
*/

void TestProfile()
{
	tml::Matrix<int> m1(1000, 1000);
	tml::Matrix<int> m2(1000, 1000);
	auto t1 = std::chrono::high_resolution_clock::now();
	tml::Matrix<int> result = tml::eager::Matmul(m1, m2, tml::execution::tbb);
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms." << std::endl;
	std::cout << result.GetShape() << std::endl;
	t1 = std::chrono::high_resolution_clock::now();
	result = tml::eager::Matmul(m2, m1, tml::execution::omp);
	t2 = std::chrono::high_resolution_clock::now();
	std::cout << "Elapsed time: " << std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count() << "ms." << std::endl;
	std::cout << result.GetShape() << std::endl;
	//std::cout << result << std::endl;
}

int main()
{
	TestProfile();
	tml::Matrix<int> m1 = tml::Matrix<int>::Arange(4, 6);
	tml::Matrix<int> m2 = tml::Matrix<int>::Arange(4, 4);
	tml::Matrix<int> m3 = tml::Matrix<int>::Arange(4, 4);
	std::cout << m1 << std::endl;
	std::cout << tml::eager::Argmax(m1, tml::execution::omp) << std::endl;
	std::cout << tml::eager::ArgmaxRows(m1, tml::execution::omp) << std::endl;
	std::cout << tml::eager::ArgmaxColumns(m1, tml::execution::omp) << std::endl;
	std::cin.get();
	return 0;
}
