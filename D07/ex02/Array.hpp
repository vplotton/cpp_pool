#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	public:
		inline explicit Array<T>() : m_size(0), m_array(NULL) {}

		inline explicit Array<T>(unsigned int size) :
			m_size(size), m_array(new T[m_size])
	{
		for (unsigned int i = 0 ; i < size ; ++i)
		{
			m_array[i] = T();
		}
	}

		inline explicit Array<T>(Array const & src) : m_size(0), m_array(NULL)
		{
			*this = src;
		}

		inline ~Array<T>() { delete [] m_array; }

		inline Array    &operator=(Array const & rhs)
		{
			if (this != &rhs)
			{
				if (m_size)
				{
					delete m_array;
				}
				m_size = rhs.m_size;
				m_array = new T[m_size];
				for (unsigned int i = 0 ; i < m_size ; ++i)
				{
					m_array[i] = rhs.m_array[i];
				}
			}
			return *this;
		}

		inline T    &operator[](unsigned int i)
		{
			if (i >= m_size)
			{
				throw (std::out_of_range("std::out_of_range"));
			}
			return m_array[i];
		}

		inline size_t   size() const { return m_size; }

	private:
		size_t  m_size;
		T       *m_array;
};

#endif /* !ARRAY_HPP */
