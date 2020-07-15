#pragma once

#include <iterator>

namespace tml
{
    namespace eager
    {
        namespace details
        {
            namespace backend
            {
                template<typename Scalar=std::size_t>
                class counter
                {
                public:
                    class iterator
                    {
                    public:
                        using iterator_category = std::random_access_iterator_tag;
                        using value_type = Scalar;
                        using difference_type = Scalar;
                        using pointer = Scalar*;
                        using reference = Scalar&;

                        iterator() : m_Value(0) {}
                        iterator(value_type val) : m_Value(val) {}
                        iterator(const iterator& iter) : m_Value(iter.m_Value) {}
                        iterator& operator=(const iterator& iter)
                        {
                            m_Value = iter.m_Value;
                            return *this;
                        }
                        iterator& operator=(value_type val) 
                        {
                            m_Value = val;
                            return *this;
                        }
                        
                        bool operator==(const iterator& rhs) const {return m_Value == rhs.m_Value;}
                        bool operator!=(const iterator& rhs) const {return m_Value != rhs.m_Value;}
                        iterator& operator+=(difference_type val) {m_Value+=val;return* this;}
                        iterator& operator-=(difference_type val) {m_Value-=val;return *this;}
                        iterator operator+(difference_type val) const {return iterator(m_Value+val);}
                        iterator operator-(difference_type val) const {return iterator(m_Value-val);}
                        iterator operator+(iterator iter) const {return iterator(m_Value + iter.m_Value);}
                        iterator operator-(iterator iter) const {return iterator(m_Value - iter.m_Value);}
                        iterator& operator++() {++m_Value;return *this;}
                        iterator operator++(int) {auto iter{*this}; ++m_Value; return iter;}
                        iterator& operator--() {--m_Value;return *this;}
                        iterator operator--(int) {auto iter{*this}; --m_Value; return iter;}
                        const value_type& operator*() const {return m_Value;}
                        value_type& operator*() {return m_Value;}
                        operator value_type() const {return m_Value;}
                    private:
                        value_type m_Value;
                    };
                private:
                    iterator m_Begin;
                    iterator m_End;
                public:
                    counter(const Scalar begin, const Scalar end) : m_Begin(begin), m_End(end) {}
                    iterator begin() const {return m_Begin;}
                    iterator end() const {return m_End;}
                };
            };
        };
    };
};