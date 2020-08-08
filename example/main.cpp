#include <tml/tml.hpp>
#include <iostream>

int main()
{
  tml::tensor<float, 2, 2> t1;
  tml::tensor<int, 2, 2> t2;
  std::cout << t1.size() << std::endl;
  tml::tensor<float, 2, 2> res = t1 + t2;
}
