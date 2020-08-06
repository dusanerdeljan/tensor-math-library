#pragma once

#include <tml/core/fwd.hpp>

namespace tml {
namespace internal {
  template<std::size_t... Indices>
  constexpr std::size_t indices_product_v = (Indices * ...);
}
}