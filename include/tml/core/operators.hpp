#pragma once

#include <tml/core/fwd.hpp>
#include <tml/internal/functors.hpp>

namespace tml {
template<typename DTypeLeft, typename DTypeRight, std::size_t... Indices>
inline constexpr expression<binary_expression<const DTypeLeft *, const DTypeRight *, internal::add_op<DTypeLeft, DTypeRight>>, Indices...> operator+(const tensor<DTypeLeft, Indices...> &left, const tensor<DTypeRight, Indices...> &right)
{
  using expr_type = binary_expression<const DTypeLeft *, const DTypeRight *, internal::add_op<DTypeLeft, DTypeRight>>;
  return expression<expr_type, Indices...>{ expr_type{ left.data(), right.data(), internal::add_op<DTypeLeft, DTypeRight>{} } };
}
}// namespace tml