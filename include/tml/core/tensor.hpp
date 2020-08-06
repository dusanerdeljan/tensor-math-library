#pragma once

#include <tml/core/fwd.hpp>
#include <tml/internal/utility.hpp>
#include <array>
#include <algorithm>

namespace tml {
template<typename Scalar, std::size_t... Indices>
class tensor
{
public:
  using containter_t = std::array<Scalar, internal::indices_product_v<Indices...>>;

  tensor() = default;
  tensor(tensor &&) = default;
  tensor(const tensor &) = default;
  tensor &operator=(tensor &&) = default;
  tensor &operator=(const tensor &) = default;
  ~tensor() = default;

  // Expression constructor and assignment operators
  //template<typename ExpressionType>
  //constexpr tensor(const expression<tensor, ExpressionType> &expr) : m_data{}
  //{
  //  assign_op{}(*this, expr);
  //}

  // Getting reference to data
  constexpr std::size_t size() const { return internal::indices_product_v<Indices...>; }
  constexpr containter_t &containter() { return m_data; }
  constexpr const containter_t &containter() const { return m_data; }
  constexpr Scalar *data() { return &m_data[0]; }
  constexpr const Scalar *data() const { return &m_data[0]; }
  constexpr auto begin() { return m_data.begin(); }
  constexpr auto end() { return m_data.end(); }
  constexpr auto cbegin() const { return m_data.cbegin(); }
  constexpr auto cend() const { return m_data.cend(); }
  constexpr auto begin() const { return cbegin(); }
  constexpr auto end() const { return m_data.end(); }

  constexpr static tensor arange() noexcept
  {
    tensor t;
    std::generate(t.begin(), t.end(), [i = 0]() mutable { return static_cast<Scalar>(i++); });
    return t;
  }

private:
  containter_t m_data{};
};
}// namespace tml
