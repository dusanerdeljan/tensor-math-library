#pragma once

#include <tml/core/fwd.hpp>
#include <tml/internal/functors.hpp>

namespace tml {

template<typename DTypeLeft, typename DTypeRight, std::size_t... Indices>
inline constexpr auto operator+(const tensor<DTypeLeft, Indices...> &left, const tensor<DTypeRight, Indices...> &right)
{
  using expr_type = binary_expression<const DTypeLeft *, const DTypeRight *, internal::add_op<DTypeLeft, DTypeRight>>;
  return expression<expr_type, Indices...>{ expr_type{ left.data(), right.data(), internal::add_op<DTypeLeft, DTypeRight>{} } };
}

template<typename Scalar, typename ExprType, std::size_t... Indices>
inline constexpr auto operator+(const tensor<Scalar, Indices...> &left, const expression<ExprType, Indices...> &right)
{
  using expr_type = binary_expression<const Scalar *, expression<ExprType, Indices...>, internal::add_op<Scalar, ExprType::scalar_t>>;
  return expression<expr_type, Indices...>{ expr_type{ left.data(), right, internal::add_op<Scalar, ExprType::scalar_t>{} } };
}

template<typename Scalar, typename ExprType, std::size_t... Indices>
inline constexpr auto operator+(const expression<ExprType, Indices...> &left, const tensor<Scalar, Indices...> &right)
{
  using expr_type = binary_expression<expression<ExprType, Indices...>, const Scalar *, internal::add_op<ExprType::scalar_t, Scalar>>;
  return expression<expr_type, Indices...>{ expr_type{ left, right.data(), internal::add_op<ExprType::scalar_t, Scalar>{} } };
}

template<typename Left, typename Right, std::size_t... Indices>
inline constexpr auto operator+(const expression<Left, Indices...> &left, const expression<Right, Indices...> &right)
{
  using expr_type = binary_expression<expression<Left, Indices...>, expression<Right, Indices...>, internal::add_op<Left::scalar_t, Right::scalar_t>>;
  return expression<expr_type, Indices...>{ expr_type{ left, right, internal::add_op<Left::scalar_t, Right::scalar_t>{} } };
}
}// namespace tml