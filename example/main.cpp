#include <tml/tml.hpp>
#include <iostream>

int main()
{
  //tml::tensor<float, 2, 4> t3;
  const auto t1 = tml::arange<float, 2, 2>();
  const auto t2 = tml::arange<int, 2, 2>();
  auto expr = t1 + t2;
  auto res = tml::eval(expr);
  for (auto i = 0; i < res.size(); ++i) {
    std::cout << res.data()[i] << std::endl;
  }
}
