#pragma once

#include <cmath>
#include <numeric>
#include "../ExecutionPolicy.hpp"
#include "../../../matrix/Matrix.hpp"

#define TML_PRINT_BACKEND_NAME 1

#define TML_STRONG_INLINE static inline

#define TML_INLINE inline

#if TML_HAS_CPP17_STL
#define TML_ACCUMULATE std::reduce
#define TML_TRANSFORM_REDUCE std::transform_reduce
#else
#define TML_ACCUMULATE std::accumulate
#define TML_TRANSFORM_REDUCE std::inner_product
#endif

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename T>
			struct invalid_backend_type : std::false_type {};
		}
	}
}

#define TML_UNSUPPORTED_BACKEND(Backend) static_assert(tml::eager::details::invalid_backend_type<Backend>::value, "Selected backend is not supported.")

#if TML_PRINT_BACKEND_NAME
#define TML_LOG_BACKEND(backend) std::cout << "running " << backend << " backend." << std::endl
#else
#define TML_LOG_BACKEND(backend)
#endif