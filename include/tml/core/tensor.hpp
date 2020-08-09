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
  using containter_t = std::array<Scalar, internal::tensor_traits<tensor<Scalar, Indices...>>::size>;

  tensor() = default;
  tensor(tensor &&) = default;
  tensor(const tensor &) = default;
  tensor &operator=(tensor &&) = default;
  tensor &operator=(const tensor &) = default;
  ~tensor() = default;

  // Expression constructor and assignment operators
  template<typename ExpressionType>
  constexpr tensor(const expression<ExpressionType, Indices...> &expr) : m_data{}
  {
    for (auto i = 0; i < m_data.size(); ++i) {
      m_data[i] = static_cast<Scalar>(expr[i]);
    }
  }

  // Getting reference to data
  constexpr std::size_t size() const { return internal::tensor_traits<tensor<Scalar, Indices...>>::size; }
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

private:
  containter_t m_data{};
};
}// namespace tml
