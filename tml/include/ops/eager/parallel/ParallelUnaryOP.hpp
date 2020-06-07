#pragma once

#include "backends\tbb\TBBBackend.hpp"
#include "backends\omp\OMPBackend.hpp"

namespace tml
{
	namespace eager
	{
		namespace details
		{
			template<typename Scalar>
			void ParallelAbs(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}

			template<typename Scalar>
			void ParallelCos(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cos(x)); }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cos(x)); });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}

			template<typename Scalar>
			void ParallelCosh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cosh(x)); }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cosh(x)); });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}

			template<typename Scalar>
			void ParallelCot(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(1.0 / std::tan(x)); }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(1.0 / std::tan(x)); });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}

			template<typename Scalar>
			void ParallelExp(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::exp(x)); }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::exp(x)); });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}

			template<typename Scalar>
			void ParallelLog(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::log(x)); }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::log(x)); });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}

			template<typename Scalar>
			void ParallelNeg(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return -x }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return -x });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}

			template<typename Scalar>
			void ParallelSin(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sin(x)); }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sin(x)); });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}

			template<typename Scalar>
			void ParallelSinh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sinh(x)); }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sinh(x)); });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}

			template<typename Scalar>
			void ParallelSqrt(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sqrt(x)); }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sqrt(x)); });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}

			template<typename Scalar>
			void ParallelSquare(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return x*x; }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return x*x; });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}

			template<typename Scalar>
			void ParallelTan(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tan(x)); }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tan(x)); });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}

			template<typename Scalar>
			void ParallelTanh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::Backend backend)
			{
				switch (backend)
				{
				case tml::TBB:
					tbbbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tanh(x)); }, tml::ONE_OVER_CORES);
					break;
				case tml::OMP:
					ompbackend::ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tanh(x)); });
					break;
				case tml::OPENCL:
					break;
				case tml::CUDA:
					break;
				case tml::STL:
					break;
				default:
					break;
				}
			}
		}
	}
}
