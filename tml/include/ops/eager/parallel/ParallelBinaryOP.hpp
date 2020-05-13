#pragma once

#include <tbb\task.h>
#include <tbb\parallel_for.h>
#include <tbb\blocked_range.h>
#include "ParallelUnaryOP.hpp"
#include "..\ExecutionPolicy.hpp"
#include "..\..\..\matrix\Matrix.hpp"

namespace tml
{
	template<typename LeftIter, typename RightIter, typename ResultIter, typename OP>
	class BinaryTask : public tbb::task
	{
	private:
		LeftIter m_Left;
		LeftIter m_End;
		RightIter m_Right;
		ResultIter m_Result;
		OP m_Op;
	public:
		BinaryTask(const LeftIter& leftBegin, const LeftIter& leftEnd, const RightIter& rightBegin, const ResultIter& result, OP&& op)
			: m_Left(leftBegin), m_End(leftEnd), m_Right(rightBegin), m_Result(result), m_Op(std::move(op)) { }
		tbb::task* execute()
		{
			std::transform(m_Left, m_End, m_Right, m_Result, m_Op);
			return NULL;
		}
	};

	namespace eager
	{
		template<typename Scalar, typename OP>
		void ParallelCustomBinaryOPSingleRow(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
		{
			std::cout << "parallel single row" << std::endl;
			tbb::task_list tasks;
			size_t rows = left.Rows(), cols = left.Columns();
			typedef tml::BinaryTask<typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::iterator, OP> TaskType;
			for (size_t i = 0; i < rows; ++i)
				tasks.push_back(*new(tbb::task::allocate_root()) TaskType(left.cbegin() + i*cols, left.cbegin() + (i + 1)*cols, right.cbegin() + i*cols, result.begin() + i*cols, std::move(op)));
			tbb::task::spawn_root_and_wait(tasks);
		}

		template<typename Scalar, typename OP>
		void ParallelCustomBinaryOPSingleColumn(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
		{
			std::cout << "parallel single column" << std::endl;
			tbb::task_list tasks;
			size_t rows = left.Rows(), cols = left.Columns();
			typedef tml::BinaryTask<typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::const_iterator, typename tml::Matrix<Scalar>::iterator, OP> TaskType;
			for (size_t i = 0; i < cols; ++i)
				tasks.push_back(*new(tbb::task::allocate_root()) TaskType(left.cbegin() + i*rows, left.cbegin() + (i + 1)*rows, right.cbegin() + i*rows, result.begin() + i*rows, std::move(op)));
			tbb::task::spawn_root_and_wait(tasks);
		}

		template<typename Scalar, typename OP>
		void ParallelCustomBinaryOPOneOverCores(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
		{
#pragma message("[TML ERROR] ParallelCustomBinaryOPOneOverCores not yet implemented.")
		}

		template<typename Scalar, typename OP>
		void ParallelCustomBinaryOPParallelFor(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op)
		{
			std::cout << "parallel parallel for" << std::endl;
			size_t grainSize = left.Size() / tml::HardawreConcurrency;
			tbb::parallel_for(tbb::blocked_range<size_t>(0, left.Size(), grainSize), [&](tbb::blocked_range<size_t> range)
			{
				for (size_t i = range.begin(); i != range.end(); ++i)
					result[i] = op(left[i], right[i]);
			}, tbb::auto_partitioner());
		}

		template<typename Scalar, typename OP>
		void ParallelCustomBinaryOP(const tml::Matrix<Scalar>& left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op, tml::ParallelismPolicy parallelism)
		{
			switch (parallelism)
			{
			case tml::SINGLE_ROW:
				ParallelCustomBinaryOPSingleRow(left, right, result, std::move(op));
				break;
			case tml::SINGLE_COLUMN:
				ParallelCustomBinaryOPSingleColumn(left, right, result, std::move(op));
				break;
			case tml::ONE_OVER_CORES:
				ParallelCustomBinaryOPOneOverCores(left, right, result, std::move(op));
				break;
			case tml::PARALLEL_FOR:
				ParallelCustomBinaryOPParallelFor(left, right, result, std::move(op));
				break;
			}
		}

		template<typename Scalar, typename OP>
		void ParallelCustomBinaryOP(const tml::Matrix<Scalar>& left, Scalar right, tml::Matrix<Scalar>& result, OP&& op, tml::ParallelismPolicy parallelism)
		{
			switch (parallelism)
			{
			case tml::SINGLE_ROW:
				ParallelCustomUnaryOPSingleRow(left, result, [=](double x) { return op(x, right); });
				break;
			case tml::SINGLE_COLUMN:
				ParallelCustomUnaryOPSingleColumn(left, result, [=](double x) { return op(x, right); });
				break;
			case tml::ONE_OVER_CORES:
				ParallelCustomUnaryOPOneOverCores(left, result, [=](double x) { return op(x, right); });
				break;
			case tml::PARALLEL_FOR:
				ParallelCustomUnaryOPParallelFor(left, result, [=](double x) { return op(x, right); });
				break;
			}
		}

		template<typename Scalar, typename OP>
		void ParallelCustomBinaryOP(Scalar left, const tml::Matrix<Scalar>& right, tml::Matrix<Scalar>& result, OP&& op, tml::ParallelismPolicy parallelism)
		{
			switch (parallelism)
			{
			case tml::SINGLE_ROW:
				ParallelCustomUnaryOPSingleRow(right, result, [=](double x) { return op(left, x); });
				break;
			case tml::SINGLE_COLUMN:
				ParallelCustomUnaryOPSingleColumn(right, result, [=](double x) { return op(left, x); });
				break;
			case tml::ONE_OVER_CORES:
				ParallelCustomUnaryOPOneOverCores(right, result, [=](double x) { return op(left, x); });
				break;
			case tml::PARALLEL_FOR:
				ParallelCustomUnaryOPParallelFor(right, result, [=](double x) { return op(left, x); });
				break;
			}
		}
	}
}
