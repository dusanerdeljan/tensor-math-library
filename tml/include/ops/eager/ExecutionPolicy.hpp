#pragma once
#include <thread>

namespace tml
{
	static const unsigned int HardawreConcurrency = std::thread::hardware_concurrency();

	enum ExecutionPolicy { SERIAL, PARALLEL };

	enum ParallelismPolicy { SINGLE_ROW, SINGLE_COLUMN, ONE_OVER_CORES, PARALLEL_FOR };
}
