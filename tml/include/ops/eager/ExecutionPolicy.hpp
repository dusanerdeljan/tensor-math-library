#pragma once
#include <thread>

namespace tml
{
	static const unsigned int HardawreConcurrency = std::thread::hardware_concurrency();

	enum ExecutionPolicy { SERIAL, PARALLEL };

	enum ParallelismPolicy { SINGLE_ROW, SINGLE_COLUMN, ONE_OVER_CORES, PARALLEL_FOR };

	namespace eager
	{
		namespace details
		{
			struct TBB {};
			struct OMP {};
			struct OPENCL {};
			struct CUDA {};
			struct STL {};
			struct SEQ {};
		}
	}

	namespace execution
	{
		static eager::details::TBB tbb;
		static eager::details::OMP omp;
		static eager::details::OPENCL opencl;
		static eager::details::CUDA cuda;
		static eager::details::STL stl;
		static eager::details::SEQ seq;
	}
}
