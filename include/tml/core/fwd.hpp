#pragma once

#include <cstddef>

namespace tml {
// Forward declarations
template<typename Scalar, std::size_t... Indices>
class tensor;

template<typename Scalar, std::size_t Rows, std::size_t Columns>
using matrix = tensor<Scalar, Rows, Columns>;

template<typename Scalar, std::size_t NumElements>
using vector = tensor<Scalar, NumElements>;

namespace internal {
  template<typename Tensor>
  struct tensor_traits;
}// namespace internal

}// namespace tml