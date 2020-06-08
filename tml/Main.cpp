#include <iostream>
#include "include\tml.hpp"

/*!
* TODOS:
*
* 1. Multi-backend for matrix multiplication, transpose and reduction ops
* 2. Remove unnecessary if/switch statements via partial template specialization
*
*/

void TestProfile()
{
	tml::Matrix<int> m1(10000, 10000);
	tml::Matrix<int> m2(10000, 10000);
	tbb::tick_count begin = tbb::tick_count::now();
	auto result = tml::eager::Add(m1, m2, tml::execution::omp);
	tbb::tick_count end = tbb::tick_count::now();
	std::cout << "Elapsed time: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	std::cout << result.GetShape() << std::endl;
	begin = tbb::tick_count::now();
	auto r2 = tml::eager::Add(m1, m2, tml::execution::tbb);
	end = tbb::tick_count::now();
	std::cout << "Elapsed time: " << (end - begin).seconds() * 1000 << "ms." << std::endl;
	std::cout << r2.GetShape() << std::endl;
	//std::cout << result << std::endl;
}

int main()
{
	TestProfile();
	tml::Matrix<int> m1 = tml::Matrix<int>::Arange(4, 4);
	tml::Matrix<int> m2 = tml::Matrix<int>::Arange(4, 4);
	tml::Matrix<int> m3 = tml::Matrix<int>::Arange(4, 4);
	std::cout << tml::eager::Mul(m1, m2) << std::endl;
	std::cout << tml::eager::Mul(m1, m2, tml::execution::tbb) << std::endl;
	std::cout << tml::eager::Mul(m1, m2, tml::execution::omp) << std::endl;
	std::cin.get();
	return 0;
}