#pragma once

namespace tml
{
	namespace lazy
	{
		template <typename Scalar>
		struct AddOP
		{
			static inline Scalar op(Scalar left, Scalar right) { return left + right; }
		};
	}
}
