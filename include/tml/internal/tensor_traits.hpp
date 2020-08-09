#pragma once

#include <tml/core/fwd.hpp>
#include <tml/internal/utility.hpp>

namespace tml {
namespace internal {
  template<typename Scalar, std::size_t... Indices>
  struct tensor_traits<tensor<Scalar, Indices...>>
  {
    using sclar_type = typename Scalar;
    constexpr static std::size_t size = indices_product_v<Indices...>;
  };

  template<typename Operator>
  struct operator_traits
  {
    using scalar_type = typename Operator::result_type;
  };

  template<typename T>
  struct is_tensor
  {
    constexpr static bool value = false;
  };

  template<typename Scalar, std::size_t... Indices>
  struct is_tensor<tensor<Scalar, Indices...>>
  {
    constexpr static bool value = true;
  };
}// namespace internal
}// namespace tml