#pragma once

#include <algorithm>
#include <array>

#include <tml/core/fwd.hpp>

namespace tml {

namespace internal {
  template<typename Scalar, std::size_t... Indices>
  struct arange_helper
  {
    constexpr tensor<Scalar, Indices...> operator()() const noexcept
    {
      tensor<Scalar, Indices...> t;
      std::generate(t.begin(), t.end(), [i = 0]() mutable { return static_cast<Scalar>(i++); });
      return t;
    }
  };

  template<typename Scalar, std::size_t... Indices>
  struct value_initializer_helper
  {
    constexpr tensor<Scalar, Indices...> operator()(Scalar value) const noexcept
    {
      tensor<Scalar, Indices...> t;
      std::fill(t.begin(), t.end(), value);
      return t;
    }
  };
}// namespace internal

template<typename ExpressoinType, std::size_t... Indices>
constexpr auto eval(const expression<ExpressoinType, Indices...> &expr)
{
  return tensor<ExpressoinType::scalar_t, Indices...>(expr);
}

template<typename Scalar, std::size_t... Indices>
constexpr tensor<Scalar, Indices...> arange() noexcept
{
  return internal::arange_helper<Scalar, Indices...>{}();
}

template<typename Scalar, std::size_t... Indices>
constexpr tensor<Scalar, Indices...> ones() noexcept
{
  return internal::value_initializer_helper<Scalar, Indices...>{}(1);
}

template<typename Scalar, std::size_t... Indices>
constexpr tensor<Scalar, Indices...> zeros() noexcept
{
  return internal::value_initializer_helper<Scalar, Indices...>{}(0);
}

template<typename Scalar, typename OtherDType, std::size_t... Indices>
constexpr tensor<Scalar, Indices...> ones_like(const tensor<OtherDType, Indices...> &other)
{
  return internal::value_initializer_helper<Scalar, Indices...>{}(1);
}

template<typename Scalar, typename OtherDType, std::size_t... Indices>
constexpr tensor<Scalar, Indices...> zeros_like(const tensor<OtherDType, Indices...> &other)
{
  return internal::value_initializer_helper<Scalar, Indices...>{}(0);
}
}// namespace tml