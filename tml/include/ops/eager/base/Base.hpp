#pragma once

#include <cmath>
#include "../ExecutionPolicy.hpp"
#include "../../../matrix/Matrix.hpp"

#define TML_PRINT_BACKEND_NAME 1

#define TML_STRONG_INLINE static inline

#define TML_INLINE inline

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename T>
			struct InvalidBackendType : std::false_type {};
		}
	}
}

#define TML_UNSUPPORTED_BACKEND(Backend) static_assert(tml::eager::details::InvalidBackendType<Backend>::value, "Selected backend is not supported.")

#if TML_PRINT_BACKEND_NAME
#define TML_LOG_BACKEND(backend) std::cout << "running " << backend << " backend." << std::endl
#else
#define TML_LOG_BACKEND(backend)
#endif