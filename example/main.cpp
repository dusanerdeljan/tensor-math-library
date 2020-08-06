#include <tml/tml.hpp>
#include <iostream>

int main()
{
  tml::tensor<float, 2, 2> t1;
  std::cout << t1.size() << std::endl;
}
