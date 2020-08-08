#pragma once

#include <tml/core/fwd.hpp>

namespace tml {
template<typename ExpressionType, std::size_t... Indicies>
class expression
{
private:
  ExpressionType m_expression;
  using scalar_t = typename ExpressionType::scalar_t;

public:
  explicit constexpr expression(ExpressionType expression) : m_expression(std::move(expression)) {}
  constexpr scalar_t &operator[](const std::size_t index) { return m_expression[index]; }
  constexpr const scalar_t &operator[](const std::size_t index) const { return m_expression[index]; }
};

template<typename LeftIter, typename RightIter, typename Operator>
class binary_expression
{
private:
  LeftIter m_left;
  RightIter m_right;
  Operator m_operator;

public:
  using scalar_t = typename internal::operator_traits<Operator>::scalar_type;
  constexpr binary_expression(LeftIter left, RightIter right, Operator op)
    : m_left(std::move(left)), m_right(std::move(right)), m_operator(std::move(op)) {}
  constexpr scalar_t &operator[](const std::size_t index) { return m_operator(m_left[index], m_right[index]); }
  constexpr const scalar_t &operator[](const std::size_t index) const { return m_operator(m_left[index], m_right[index]); }
};
}// namespace tml