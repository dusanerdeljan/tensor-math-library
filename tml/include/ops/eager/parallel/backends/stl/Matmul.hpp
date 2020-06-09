#pragma once

#if TML_HAS_CPP17_STL
#include <execution>
#include <algorithm>
#include "../../../base/MatmulBase.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			namespace backend
			{
				template<typename Scalar>
				struct MatmulBackend<Scalar, STL>
				{
					TML_STRONG_INLINE void DoOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result)
					{
						std::cout << "running stl backend" << std::endl;
						const tml::Matrix<Scalar> newRight = tml::eager::Transpose(right, tml::execution::stl);
						size_t r1 = left.Rows(), c1 = left.Columns(), r2 = right.Rows(), c2 = right.Columns();
						for (size_t i = 0; i < r1; i += 32)
							for (size_t j = 0; j < c2; j += 32)
								for (size_t br = 0; br < 32 && i + br < r1; ++br)
									for (size_t bc = 0; bc < 32 && j + bc < c2; ++bc)
										result[j + bc + (i + br) * c2] = std::transform_reduce(std::execution::seq, left.cbegin() + (i + br) * c1, left.cbegin() + (i + br + 1) * c1, newRight.cbegin() + (j + bc) * r2, static_cast<Scalar>(0));
					}
				};
			}
		}
	}
}
#endif