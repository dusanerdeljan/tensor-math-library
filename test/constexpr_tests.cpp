#include <catch2/catch.hpp>
#include <tml/tml.hpp>

// TODO: Test constexpr behaviour

TEST_CASE("Test size memeber function.", "[tml::tensor::size()]")
{
  tml::tensor<int, 2, 2, 2> t1;
  STATIC_REQUIRE(t1.size() == 8);
}
