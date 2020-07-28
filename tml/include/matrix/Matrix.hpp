#pragma once

#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <initializer_list>
#include <iterator>

#include "Shape.hpp"
#include "../ops/eager/ExecutionPolicy.hpp"

template<typename Scalar, typename T> struct expr_op;

#define TML_DEBUG_CTOR_PRINTS 1
#define TML_USE_CUSTOM_MATRIX_ITERATOR 0

#if TML_HAS_TBB
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
#elif TML_HAS_OMP
#include <omp.h>
#endif

#if TML_DEBUG_CTOR_PRINTS
#define LOG(x) std::cout << x << std::endl
#else
#define LOG(x)
#endif

namespace tml
{
	enum OwnershipPolicy {VIEW, COPY};

	template<typename Scalar=double>
	class matrix
	{
	private:
		Scalar* m_data;
		shape m_shape;
		bool m_view = false;
	public:
#if TML_USE_CUSTOM_MATRIX_ITERATOR
		class iterator;
		class const_iterator;
#else
		typedef Scalar* iterator;
		typedef const Scalar* const_iterator;
#endif

		matrix(size_t rows, size_t cols) : m_data(new Scalar[rows*cols]), m_shape(rows, cols)
		{
			for (size_t i = 0; i < m_shape.size; ++i) m_data[i] = (Scalar)i;
		}

		matrix(Scalar* data, const shape& shape, tml::OwnershipPolicy ownership = tml::VIEW) : m_data(nullptr), m_shape(shape)
		{
			if (ownership == tml::VIEW)
			{
				m_data = data;
				m_view = true;
			}
			else
			{
				m_data = new Scalar[shape.size];
				memcpy(m_data, data, sizeof(Scalar)*shape.size);
			}
		}

		matrix(shape shape) : m_data(new Scalar[shape.size]), m_shape(shape)
		{
			LOG("shape constructor");
		}

		template<typename T>
		matrix(const expr_op<Scalar, T>& expr) : m_data(new Scalar[expr.shape.size]), m_shape(expr.shape)
		{
			LOG("expr constructor");
			assign_expr(expr);
		}

		matrix(const matrix<Scalar>& matrix) : m_data(new Scalar[matrix.m_shape.size]), m_shape(matrix.m_shape)
		{
			LOG("copy constructor");
			memcpy(m_data, matrix.m_data, sizeof(Scalar)*m_shape.size);
		}

		matrix(std::initializer_list<Scalar> init) : m_data(new Scalar[init.size()]), m_shape({ 1, init.size() })
		{
			LOG("initializer list constructor");
			std::move(init.begin(), init.end(), m_data);
		}

		matrix(std::initializer_list<Scalar> init, const shape& shape) : m_data(new Scalar[shape.size]), m_shape(shape)
		{
			LOG("initializer initializer list constructor");
			std::move(init.begin(), init.end(), m_data);
		}

		template<typename DType>
		matrix(const matrix<DType>& matrix) : m_data(new Scalar[matrix.size()]), m_shape(matrix.get_shape())
		{
			LOG("copy new type constructor");
			iterator writer = begin();
			for (auto it = matrix.cbegin(); it != matrix.cend(); ++it, ++writer)
				*writer = static_cast<Scalar>(*it);
		}

		matrix(matrix<Scalar>&& matrix) noexcept : m_data(matrix.m_data), m_shape(matrix.m_shape)
		{
			LOG("move constructor");
			matrix.m_data = nullptr;
		}

		~matrix() { if (!m_view) { LOG("destructor"); delete[] m_data; } }

		template<typename T>
		matrix<Scalar>& operator=(const expr_op<Scalar, T>& expr)
		{
			LOG("expr assignment");
			if (m_shape.size != expr.shape.size)
			{
				m_data = (Scalar*)realloc(m_data, sizeof(Scalar)*expr.shape.size);
			}
			assign_expr(expr);
			return *this;
		}

		matrix<Scalar>& operator=(const matrix<Scalar>& matrix)
		{
			LOG("copy assignment");
			Scalar* data = new Scalar[matrix.m_shape.size];
			memcpy(data, matrix.m_data, sizeof(Scalar)*matrix.m_shape.size);
			delete[] m_data;
			m_data = data;
			m_shape = matrix.m_shape;
			return *this;
		}

		template<typename DType>
		matrix<Scalar>& operator=(const matrix<DType>& matrix)
		{
			LOG("copy new type assignment");
			Scalar* data = new Scalar[matrix.size()];
			iterator writer = data;
			for (auto it = matrix.cbegin(); it != matrix.cend(); ++it, ++writer)
				*writer = static_cast<Scalar>(*it);
			delete[] m_data;
			m_data = data;
			m_shape = matrix.get_shape();
			return *this;
		}

		matrix<Scalar>& operator=(matrix<Scalar>&& matrix) noexcept
		{
			LOG("move assignment");
			delete[] m_data;
			m_data = matrix.m_data;
			m_shape = matrix.m_shape;
			matrix.m_data = nullptr;
			return *this;
		}

		static matrix<Scalar> zeros(shape shape)
		{
			matrix<Scalar> matrix(shape);
			std::fill(matrix.begin(), matrix.end(), static_cast<Scalar>(0.0));
			return std::move(matrix);
		}

		template<typename DType>
		static matrix<Scalar> zeros_like(const matrix<DType>& m)
		{
			matrix<Scalar> result (m.get_shape());
			std::fill(result.begin(), result.end(), static_cast<Scalar>(0.0));
			return std::move(m);
		}

		static matrix<Scalar> ones(shape shape)
		{
			matrix<Scalar> matrix(shape);
			std::fill(matrix.begin(), matrix.end(), static_cast<Scalar>(1.0));
			return std::move(matrix);
		}

		template<typename DType>
		static matrix<Scalar> ones_like(const matrix<DType>& m)
		{
			matrix<Scalar> result(m.get_shape());
			std::fill(result.begin(), result.end(), static_cast<Scalar>(1.0));
			return std::move(m);
		}

		static matrix<Scalar> arange(size_t rows, size_t cols)
		{
			return matrix(rows, cols);
		}

		shape get_shape() const { return m_shape; }

		void set_shape(const shape& shape) { m_shape = shape; }

		inline Scalar& operator() (size_t i, size_t j) { return m_data[j + i*m_shape.columns]; }
		inline const Scalar& operator() (size_t i, size_t j) const { return m_data[j + i*m_shape.columns]; }

#if TML_USE_CUSTOM_MATRIX_ITERATOR
		inline iterator begin() { return iterator(m_data, m_data); }
		inline const_iterator cbegin() const { return const_iterator(m_data, m_data); }
		inline iterator end() { return iterator(m_data + m_shape.size, m_data); }
		inline const_iterator cend() const { return const_iterator(m_data + m_shape.size, m_data); }
#else
		inline iterator begin() { return m_data; }
		inline const_iterator cbegin() const { return m_data; }
		inline iterator end() { return m_data + m_shape.size; }
		inline const_iterator cend() const { return m_data + m_shape.size; }
#endif
		inline const_iterator begin() const { return cbegin(); }
		inline const_iterator end() const { return cend(); }

		inline size_t size() const { return m_shape.size; }

		inline size_t rows() const { return m_shape.rows; }

		inline size_t columns() const { return m_shape.columns; }

		Scalar& operator[] (size_t index) { return m_data[index]; }

		const Scalar& operator[] (size_t index) const { return m_data[index]; }

#if TML_USE_CUSTOM_MATRIX_ITERATOR
		class iterator
		{
		public:
			using iterator_category = std::random_access_iterator_tag;
			using value_type = Scalar;
			using difference_type = std::ptrdiff_t;
			using pointer = Scalar*;
			using reference = Scalar&;

			iterator() = default;
			iterator(pointer val, pointer start) : m_ptr(val), m_start(start) {}
			iterator(const iterator& iter) : m_ptr(iter.m_ptr), m_start(iter.m_start) {}
			iterator& operator=(const iterator& iter)
			{
				m_ptr = iter.m_ptr;
				m_start = iter.m_start;
				return *this;
			}
			//iterator& operator=(pointer val)
			//{
			//	m_ptr = val;
			//	return *this;
			//}

			bool operator==(const iterator& rhs) const { return m_ptr == rhs.m_ptr; }
			bool operator!=(const iterator& rhs) const { return m_ptr != rhs.m_ptr; }
			iterator& operator+=(difference_type val) { m_ptr += val; return*this; }
			iterator& operator-=(difference_type val) { m_ptr -= val; return *this; }
			iterator operator+(difference_type val) const { return iterator(m_ptr + val, m_start); }
			difference_type operator-(difference_type val) const { return m_ptr - val; }
			iterator operator+(iterator iter) const { return iterator(m_ptr + iter.m_ptr, m_start); }
			difference_type operator-(iterator iter) const { return m_ptr - iter.m_ptr; }
			iterator& operator++() { ++m_ptr; return *this; }
			iterator operator++(int) { auto iter{ *this }; ++m_ptr; return iter; }
			iterator& operator--() { --m_ptr; return *this; }
			iterator operator--(int) { auto iter{ *this }; --m_ptr; return iter; }
			const value_type& operator*() const { return *m_ptr; }
			value_type& operator*() { return *m_ptr; }
			pointer operator->() { return m_ptr; }
			const pointer operator->() const { return m_ptr; }
			operator const_iterator() const { return const_iterator(m_ptr); }
			// TODO: Probably remove this later
			reference operator[] (std::size_t index) { return m_start[index]; }
			const reference operator[] (std::size_t index) const { return m_start[index]; }
		private:
			pointer m_start = nullptr;
			pointer m_ptr = nullptr;
		};

		class const_iterator
		{
		public:
			using iterator_category = std::random_access_iterator_tag;
			using value_type = Scalar;
			using difference_type = std::ptrdiff_t;
			using pointer = Scalar*;
			using reference = Scalar&;

			const_iterator() = default;
			const_iterator(pointer val, pointer start) : m_ptr(val), m_start(start) {}
			const_iterator(const const_iterator& iter) : m_ptr(iter.m_ptr), m_start(iter.m_start) {}
			const_iterator& operator=(const const_iterator& iter)
			{
				m_ptr = iter.m_ptr;
				m_start = iter.m_start;
				return *this;
			}
			//const_iterator& operator=(pointer val)
			//{
			//	m_ptr = val;
			//	return *this;
			//}

			bool operator==(const const_iterator& rhs) const { return m_ptr == rhs.m_ptr; }
			bool operator!=(const const_iterator& rhs) const { return m_ptr != rhs.m_ptr; }
			const_iterator& operator+=(difference_type val) { m_ptr += val; return*this; }
			const_iterator& operator-=(difference_type val) { m_ptr -= val; return *this; }
			const_iterator operator+(difference_type val) const { return const_iterator(m_ptr + val, m_start); }
			difference_type operator-(difference_type val) const { return m_ptr - val; }
			const_iterator operator+(const_iterator iter) const { return const_iterator(m_ptr + iter.m_ptr, m_start); }
			difference_type operator-(const_iterator iter) const { return m_ptr - iter.m_ptr; }
			const_iterator& operator++() { ++m_ptr; return *this; }
			const_iterator operator++(int) { auto iter{ *this }; ++m_ptr; return iter; }
			const_iterator& operator--() { --m_ptr; return *this; }
			const_iterator operator--(int) { auto iter{ *this }; --m_ptr; return iter; }
			const value_type& operator*() const { return *m_ptr; }
			const pointer operator->() const { return m_ptr; }
			// TODO: Probably remove this later
			reference operator[] (std::size_t index) { return m_start[index]; }
			const reference operator[] (std::size_t index) const { return m_start[index]; }
		private:
			pointer m_start = nullptr;
			pointer m_ptr = nullptr;
		};
#endif
	private:
		template<typename T>
		void assign_expr(const expr_op<Scalar, T>& expr)
		{
#if TML_HAS_TBB
			size_t grainSize =  m_shape.size / tml::hardware_concurrency;
			tbb::parallel_for(tbb::blocked_range<size_t>(0, m_shape.size, grainSize), [&](tbb::blocked_range<size_t> range)
			{
				for (size_t i = range.begin(); i != range.end(); ++i)
					m_data[i] = expr[i];
			});
#elif TML_HAS_OMP
			omp_set_num_threads(tml::hardware_concurrency);
			#pragma omp parallel for
			for (int64_t i = 0; i < (int64_t)m_shape.size; ++i)
				m_data[i] = expr[i];
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
	std::ostream& operator << (std::ostream& out, const matrix<Scalar>& m)
	{
		for (size_t i = 0; i < m.rows(); ++i)
		{
			for (size_t j = 0; j < m.columns(); ++j)
				std::cout << std::setw(12) << std::left << m(i, j);
			std::cout << std::endl;
		}
		return out;
	}
};
