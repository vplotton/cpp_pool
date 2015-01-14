#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	public:
		__attribute__((noinline)) Array()
		{
			m_size = 0;
			m_array = NULL;
		}

		__attribute__((noinline)) Array(unsigned int size)
		{
			m_size = size;
			m_array = new T[m_size];
			for (unsigned int i = 0 ; i < size ; ++i)
			{
				m_array[i] = T();
			}
		}

		__attribute__((noinline)) Array(Array const & src)
		{
			*this = src;
		}

		__attribute__((noinline)) ~Array()
		{
			delete [] m_array;
		}

		__attribute__((noinline)) Array   &operator=(Array const & rhs)
		{
			if (this != &rhs)
			{
				m_size = rhs.m_size;
				m_array = new T[m_size];
				for (unsigned int i = 0 ; i < m_size ; ++i)
				{
					m_array[i] = rhs.m_array[i];
				}
			}
			return *this;
		}

		__attribute__((noinline)) T   &operator[](unsigned int i)
		{
			if (i >= m_size)
			{
				throw (std::out_of_range("std::out_of_range"));
			}
			return m_array[i];
		}

		__attribute__((noinline)) unsigned int    size() const
		{
			return m_size;
		}

	private:
		T       *m_array;
		unsigned int    m_size;
};

int		main()
{
	for (int i = 0 ; i < 1000 ; ++i)
	{
		Array<int>  *array = new Array<int>(1000000);
		for (int i = 0 ; i < 1000000 ; ++i)
		{
			(*array)[i] = i;
		}
		array->size();
		delete array;
	}
}
