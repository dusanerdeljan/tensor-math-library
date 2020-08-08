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

template<typename ExpressionType, std::size_t... Indices>
class expression;

template<typename LeftIter, typename RightIter, typename Operand>
class binary_expression;

namespace internal {
  template<typename Tensor>
  struct tensor_traits;

  template<typename Operator>
  struct operator_traits;
}// namespace internal

}// namespace tml