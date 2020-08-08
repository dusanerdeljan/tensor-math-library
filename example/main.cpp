#include <tml/tml.hpp>
#include <iostream>

int main()
{
  tml::tensor<float, 2, 2> t1 = tml::tensor<float, 2, 2>::arange();
  tml::tensor<int, 2, 2> t2 = tml::tensor<int, 2, 2>::arange();
  tml::tensor<float, 2, 2> res = t1 + t2;
  for (auto i = 0; i < res.size(); ++i) {
    std::cout << res.data()[i] << std::endl;
  }
}
