#ifndef GRID_HPP
# define GRID_HPP

#include "Cell.hpp"
#include <iostream>
#include <vector>

template <unsigned int HEIGTH = 19
	, unsigned int WIDTH = 19
	, class CellPolicy = Cell>
class Grid:	public CellPolicy
{
	public:
		Grid() {}
		Grid(Grid const &src): m_data(src.m_data) {}

		CellPolicy const &at(unsigned int y, unsigned int x) const
		{ return m_data[y * WIDTH + x]; }

		class iterator
		{
			public:
				iterator(iterator const &other): m_ptr(other.m_ptr) {}

				iterator() {}
				iterator(CellPolicy *ptr): m_ptr(ptr) {}


				bool	operator==(iterator const &rhs)
				{ return this->m_ptr == rhs.m_ptr; }

				bool	operator!=(iterator const &rhs)
				{ return this->m_ptr != rhs.m_ptr; }

				iterator &operator=(iterator const &rhs)
				{ return *this; }

				CellPolicy	*operator->()
				{ return m_ptr; }

				iterator &operator++()
				{ ++m_ptr; return *this; }

				iterator &operator--()
				{ --m_ptr; return *this; }

				iterator operator++(int)
				{ ++*this; return iterator(m_ptr + 1); }

                iterator operator--(int)
				{ --*this; return iterator(m_ptr - 1); }

                CellPolicy operator*() const
                { return *m_ptr; }


				iterator	&left() const
				{ return iterator(m_ptr - 1); }

				iterator	&right() const
				{ return iterator(m_ptr + 1); }

				iterator	&up() const
				{ return iterator(m_ptr - WIDTH); }

				iterator	&down() const
				{ return iterator(m_ptr + WIDTH); }

			private:
				CellPolicy	*m_ptr;

		};

		iterator begin() { return iterator(m_data); }
		iterator end() { return iterator(m_data + WIDTH * HEIGTH); }

	private:
		CellPolicy	m_data[HEIGTH * WIDTH];
};

#endif /* !GRID_HPP */
