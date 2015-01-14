#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>




template <typename T>
class Array
{
	public:
		Array()
		{
			m_size = 0;
			m_array = NULL;
		}

		Array(unsigned int size)
		{
			m_size = size;
			m_array = new T[m_size];
			try
			{
				for (unsigned int i = 0 ; i < size ; ++i)
				{
					T	*init = new T();
					m_array[i] = *init;
					delete init;
				}
			}
			catch (...)
			{
			}
		}

		Array(Array const & src)
		{
			*this = src;
		}

		~Array()
		{
			delete [] m_array;
		}

		Array	&operator=(Array const & rhs)
		{
				m_size = rhs.m_size;
				m_array = new T[m_size];
				for (unsigned int i = 0 ; i < m_size ; ++i)
				{   
					m_array[i] = rhs.m_array[i];
				}   
			return *this;
		}

		T	&operator[](unsigned int i)
		{
			if (i >= m_size)
			{
				throw (std::out_of_range("std::out_of_range"));
			}
			return m_array[i];
		}

		unsigned int	size() const
		{
			return m_size;
		}

	private:
		T		*m_array;
		unsigned int	m_size;
};

#endif /* !ARRAY_HPP */
