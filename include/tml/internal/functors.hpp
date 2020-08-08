#pragma once

#include <type_traits>

#include <tml/core/fwd.hpp>

namespace tml {
namespace internal {
  template<typename... Ts>
  struct op_base
  {
    using result_type = std::common_type_t<Ts...>;
  };

  // TODO: Probably remove this
#define TML_DEFINE_BINARY_OPERATOR_FUNCTOR(name, func)                                            \
  template<typename T1, typename T2>                                                              \
  struct name : public op_base<T1, T2>                                                            \
  {                                                                                               \
    using typename op_base<T1, T2>::result_type;                                                  \
    constexpr result_type operator()(T1 x, T2 y) const { return static_cast<result_type>(func); } \
  };

  TML_DEFINE_BINARY_OPERATOR_FUNCTOR(add_op, x + y);
  TML_DEFINE_BINARY_OPERATOR_FUNCTOR(sub_op, x - y);
  TML_DEFINE_BINARY_OPERATOR_FUNCTOR(div_op, x / y);
  TML_DEFINE_BINARY_OPERATOR_FUNCTOR(mul_op, x *y);
  TML_DEFINE_BINARY_OPERATOR_FUNCTOR(greater_than_op, x > y);
  TML_DEFINE_BINARY_OPERATOR_FUNCTOR(greater_equal_than_op, x >= y);
  TML_DEFINE_BINARY_OPERATOR_FUNCTOR(less_than_op, x < y);
  TML_DEFINE_BINARY_OPERATOR_FUNCTOR(less_equal_than_op, x <= y);
  TML_DEFINE_BINARY_OPERATOR_FUNCTOR(equal_op, x == y);
  TML_DEFINE_BINARY_OPERATOR_FUNCTOR(not_equal_op, x != y);

}// namespace internal
}// namespace tml