#pragma once

#include <tbb\task.h>
#include <tbb\parallel_for.h>
#include <tbb\blocked_range.h>
#include "..\ExecutionPolicy.hpp"
#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	template<typename ReadIter, typename WriteIter, typename OP>
	class UnaryTask : public tbb::task
	{
	private:
		ReadIter m_Begin;
		ReadIter m_End;
		WriteIter m_Result;
		OP m_Op;
	public:
		UnaryTask(const ReadIter& begin, const ReadIter& end, const WriteIter& result, OP&& op) : m_Begin(begin), m_End(end), m_Result(result), m_Op(std::move(op)) {}
		tbb::task* execute()
		{
			std::transform(m_Begin, m_End, m_Result, m_Op);
			return NULL;
		}
	};

	namespace eager
	{
		template<typename Scalar, typename OP>
		void ParallelCustomUnaryOPSingleRow(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, OP&& op)
		{
			std::cout << "parallel single row" << std::endl;
			tbb::task_list tasks;
			size_t rows = matrix.Rows(), cols = matrix.Columns();
			typedef tml::UnaryTask<typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::iterator, OP> TaskType;
			for (size_t i = 0; i < rows; ++i)
				tasks.push_back(*new(tbb::task::allocate_root()) TaskType(matrix.cbegin() + i*cols, matrix.cbegin() + (i + 1)*cols, result.begin() + i*cols, std::move(op)));
			tbb::task::spawn_root_and_wait(tasks);
		}

		template<typename Scalar, typename OP>
		void ParallelCustomUnaryOPSingleColumn(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, OP&& op)
		{
			std::cout << "parallel single column" << std::endl;
			tbb::task_list tasks;
			size_t rows = matrix.Rows(), cols = matrix.Columns();
			typedef tml::UnaryTask<typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::iterator, OP> TaskType;
			for (size_t i = 0; i < cols; ++i)
				tasks.push_back(*new(tbb::task::allocate_root()) TaskType(matrix.cbegin() + i*rows, matrix.cbegin() + (i + 1)*rows, result.begin() + i*rows, std::move(op)));
			tbb::task::spawn_root_and_wait(tasks);
		}

		template<typename Scalar, typename OP>
		void ParallelCustomUnaryOPOneOverCores(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, OP&& op)
		{
			size_t size = matrix.Size();
			typedef tml::UnaryTask<typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::iterator, OP> TaskType;
			if (size <= tml::HardawreConcurrency)
			{
				tbb::task::spawn_root_and_wait(*(new (tbb::task::allocate_root()) TaskType(matrix.cbegin(), matrix.cend(), result.begin(), std::move(op))));
			}
			else if (size % tml::HardawreConcurrency == 0)
			{
				tbb::task_list tasks;
				size_t stepSize = size / tml::HardawreConcurrency;
				for (size_t i = 0; i < size; i += stepSize)
					tasks.push_back(*(new(tbb::task::allocate_root()) TaskType(matrix.cbegin() + i, matrix.cbegin() + i + stepSize, result.begin() + i, std::move(op))));
				tbb::task::spawn_root_and_wait(tasks);
			}
			else
			{
				size_t treshold = tml::HardawreConcurrency - (size % tml::HardawreConcurrency);
				size_t value = size / tml::HardawreConcurrency;
				tbb::task_list tasks;
				size_t beginIndex = 0;
				for (size_t i = 0; i<tml::HardawreConcurrency; ++i)
				{
					size_t segmentLength = value + (i >= treshold);
					tasks.push_back(*(new(tbb::task::allocate_root()) TaskType(matrix.cbegin() + beginIndex, matrix.cbegin() + beginIndex + segmentLength, result.begin() + beginIndex, std::move(op))));
					beginIndex += segmentLength;
				}
				tbb::task::spawn_root_and_wait(tasks);
			}
		}

		template<typename Scalar, typename OP>
		void ParallelCustomUnaryOPParallelFor(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, OP&& op)
		{
			std::cout << "parallel parallel for" << std::endl;
			size_t grainSize = matrix.Size() / tml::HardawreConcurrency;
			tbb::parallel_for(tbb::blocked_range<size_t>(0, matrix.Size(), grainSize), [&](tbb::blocked_range<size_t> range)
			{
				for (size_t i = range.begin(); i != range.end(); ++i)
					result[i] = op(matrix[i]);
			}, tbb::auto_partitioner());
		}

		template<typename Scalar, typename OP>
		void ParallelCustomUnaryOP(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, OP&& op, tml::ParallelismPolicy parallelism)
		{
			switch (parallelism)
			{
			case tml::SINGLE_ROW:
				ParallelCustomUnaryOPSingleRow(matrix, result, std::move(op));
				break;
			case tml::SINGLE_COLUMN:
				ParallelCustomUnaryOPSingleColumn(matrix, result, std::move(op));
				break;
			case tml::ONE_OVER_CORES:
				ParallelCustomUnaryOPOneOverCores(matrix, result, std::move(op));
				break;
			case tml::PARALLEL_FOR:
				ParallelCustomUnaryOPParallelFor(matrix, result, std::move(op));
				break;
			}
		}

		template<typename Scalar>
		void ParallelAbs(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return std::abs(x); }, parallelism);
		}

		template<typename Scalar>
		void ParallelCos(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cos(x)); }, parallelism);
		}

		template<typename Scalar>
		void ParallelCosh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::cosh(x)); }, parallelism);
		}

		template<typename Scalar>
		void ParallelCot(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(1.0 / std::tan(x)); }, parallelism);
		}

		template<typename Scalar>
		void ParallelExp(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::exp(x)); }, parallelism);
		}

		template<typename Scalar>
		void ParallelLog(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::log(x)); }, parallelism);
		}

		template<typename Scalar>
		void ParallelNeg(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return -x }, parallelism);
		}

		template<typename Scalar>
		void ParallelSin(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sin(x)); }, parallelism);
		}

		template<typename Scalar>
		void ParallelSinh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sinh(x)); }, parallelism);
		}

		template<typename Scalar>
		void ParallelSqrt(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::sqrt(x)); }, parallelism);
		}

		template<typename Scalar>
		void ParallelSquare(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return x*x; }, parallelism);
		}

		template<typename Scalar>
		void ParallelTan(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tan(x)); }, parallelism);
		}

		template<typename Scalar>
		void ParallelTanh(const tml::Matrix<Scalar>& matrix, tml::Matrix<Scalar>& result, tml::ParallelismPolicy parallelism)
		{
			ParallelCustomUnaryOP(matrix, result, [](Scalar x) { return static_cast<Scalar>(std::tanh(x)); }, parallelism);
		}
	}
}
