#pragma once

#include <iostream>
#include <iomanip>

#include <tbb\tbb.h>
#include <tbb\parallel_for.h>
#include <tbb\blocked_range.h>

#include "Shape.hpp"

// TODO: Implement expr assignment policy configuration
#define TML_USE_PARALLEL_ASSIGNMENT

namespace tml
{
	template<typename Scalar=double>
	class Matrix
	{
	private:
		Scalar* m_Data;
		Shape m_Shape;
	public:
		typedef Scalar* iterator;
		typedef const Scalar* const_iterator;

		Matrix(size_t rows, size_t cols) : m_Data(new Scalar[rows*cols]), m_Shape(rows, cols)
		{
			for (size_t i = 0; i < m_Shape.Size; ++i) m_Data[i] = (Scalar)i;
		}

		Matrix(Shape shape) : m_Data(new Scalar[shape.Size]), m_Shape(shape)
		{
			std::cout << "shape constructor" << std::endl;
		}

		template<typename Expr>
		Matrix(Expr expr) : m_Data(new Scalar[expr.shape.Size]), m_Shape(expr.shape)
		{
			std::cout << "expr constructor" << std::endl;
			AssignExpr(expr);
		}

		Matrix(const Matrix<Scalar>& matrix) : m_Data(new Scalar[matrix.m_Shape.Size]), m_Shape(matrix.m_Shape)
		{
			std::cout << "copy constructor" << std::endl;
			memcpy(m_Data, matrix.m_Data, sizeof(Scalar)*m_Shape.Size);
		}

		template<typename DType>
		Matrix(const Matrix<DType>& matrix) : m_Data(new Scalar[matrix.Size()]), m_Shape(matrix.GetShape())
		{
			std::cout << "copy new type constructor" << std::endl;
#pragma message("[TML WARNING] You are copying a matrix of different type. Possible loss of data.")
			iterator writer = begin();
			for (auto it = matrix.cbegin(); it != matrix.cend(); ++it, ++writer)
				*writer = static_cast<Scalar>(*it);
		}

		Matrix(Matrix<Scalar>&& matrix) : m_Data(matrix.m_Data), m_Shape(matrix.m_Shape)
		{
			std::cout << "move constructor" << std::endl;
			matrix.m_Data = nullptr;
		}

		~Matrix() { delete[] m_Data; }

		template<typename Expr>
		Matrix<Scalar>& operator=(const Expr& expr)
		{
			std::cout << "expr assignment" << std::endl;
			AssignExpr(expr);
			return *this;
		}

		Matrix<Scalar>& operator=(const Matrix<Scalar>& matrix)
		{
			std::cout << "copy assignment" << std::endl;
			Scalar* data = new Scalar[matrix.m_Shape.Size];
			memcpy(data, matrix.m_Data, sizeof(Scalar)*matrix.m_Shape.Size);
			delete[] m_Data;
			m_Data = data;
			m_Shape = matrix.m_Shape;
			return *this;
		}

		template<typename DType>
		Matrix<Scalar>& operator=(const Matrix<DType>& matrix)
		{
			std::cout << "copy new type assignment" << std::endl;
#pragma message("[TML WARNING] You are copying a matrix of different type. Possible loss of data.")
			Scalar* data = new Scalar[matrix.Size()];
			iterator writer = data;
			for (auto it = matrix.cbegin(); it != matrix.cend(); ++it, ++writer)
				*writer = static_cast<Scalar>(*it);
			delete[] m_Data;
			m_Data = data;
			m_Shape = matrix.GetShape();
			return *this;
		}

		Matrix<Scalar>& operator=(Matrix<Scalar>&& matrix)
		{
			std::cout << "move assignment" << std::endl;
			delete[] m_Data;
			m_Data = matrix.m_Data;
			m_Shape = matrix.m_Shape;
			matrix.m_Data = nullptr;
			return *this;
		}

		static Matrix<Scalar> Zeros(Shape shape)
		{
			Matrix<Scalar> matrix(shape);
			std::fill(matrix.begin(), matrix.end(), static_cast<Scalar>(0.0));
			return std::move(matrix);
		}

		template<typename DType>
		static Matrix<Scalar> ZerosLike(const Matrix<DType>& matrix)
		{
			Matrix<Scalar> result (matrix.GetShape());
			std::fill(result.begin(), result.end(), static_cast<Scalar>(0.0));
			return std::move(matrix);
		}

		static Matrix<Scalar> Ones(Shape shape)
		{
			Matrix<Scalar> matrix(shape);
			std::fill(matrix.begin(), matrix.end(), static_cast<Scalar>(1.0));
			return std::move(matrix);
		}

		template<typename DType>
		static Matrix<Scalar> OnesLike(const Matrix<DType>& matrix)
		{
			Matrix<Scalar> result(matrix.GetShape());
			std::fill(result.begin(), result.end(), static_cast<Scalar>(1.0));
			return std::move(matrix);
		}

		Shape GetShape() const { return m_Shape; }

		void SetShape(const Shape& shape) { m_Shape = shape; }

		inline Scalar& operator() (size_t i, size_t j) { return m_Data[j + i*m_Shape.Columns]; }
		inline const Scalar& operator() (size_t i, size_t j) const { return m_Data[j + i*m_Shape.Columns]; }

		inline iterator begin() { return m_Data; }

		inline const_iterator cbegin() const { return m_Data; }

		inline iterator end() { return m_Data + m_Shape.Size; }

		inline const_iterator cend() const { return m_Data + m_Shape.Size; }

		inline size_t Size() const { return m_Shape.Size; }

		inline size_t Rows() const { return m_Shape.Rows; }

		inline size_t Columns() const { return m_Shape.Columns; }

		Scalar& operator[] (size_t index) { return m_Data[index]; }

		const Scalar& operator[] (size_t index) const { return m_Data[index]; }
	private:
		template<typename Expr>
		void AssignExpr(Expr expr)
		{
#ifdef TML_USE_PARALLEL_ASSIGNMENT
			size_t grainSize =  m_Shape.Size / tml::HardawreConcurrency;
			tbb::parallel_for(tbb::blocked_range<size_t>(0, m_Shape.Size, grainSize), [&](tbb::blocked_range<size_t> range)
			{
				for (size_t i = range.begin(); i != range.end(); ++i)
					m_Data[i] = expr[i];
			});
#else
			iterator beginIter = begin();
			iterator endIter = end();
			do
			{
				*beginIter = *expr;
				++expr;
			} while (++beginIter != endIter);
#endif
		}
	};

	template<typename Scalar>
	std::ostream& operator << (std::ostream& out, const Matrix<Scalar>& matrix)
	{
		for (size_t i = 0; i < matrix.Rows(); ++i)
		{
			for (size_t j = 0; j < matrix.Columns(); ++j)
				std::cout << std::setw(12) << std::left << matrix(i, j);
			std::cout << std::endl;
		}
		return out;
	}
}
