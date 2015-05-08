#ifndef ITERATOR_HPP
# define ITERATOR_HPP

template <class T, unsigned int WIDTH>
class Iterator
{
	public:
		Iterator(Iterator const &other): m_ptr(other.m_ptr) {}

		Iterator() {}
		Iterator(T *ptr): m_ptr(ptr) {}


		bool	operator==(Iterator const &rhs)
		{ return this->m_ptr == rhs.m_ptr; }

		bool	operator!=(Iterator const &rhs)
		{ return this->m_ptr != rhs.m_ptr; }

		Iterator &operator=(Iterator const &rhs)
		{ return *this; }

		T	*operator->()
		{ return m_ptr; }

		Iterator &operator++()
		{ ++m_ptr; return *this; }

		Iterator &operator--()
		{ --m_ptr; return *this; }

		Iterator operator++(int)
		{ ++*this; return Iterator(m_ptr + 1); }

		Iterator operator--(int)
		{ --*this; return Iterator(m_ptr - 1); }

		T operator*() const
		{ return *m_ptr; }


		Iterator	&left() const
		{ return Iterator(m_ptr - 1); }

		Iterator	&right() const
		{ return Iterator(m_ptr + 1); }

		Iterator	&up() const
		{ return Iterator(m_ptr - WIDTH); }

		Iterator	&down() const
		{ return Iterator(m_ptr + WIDTH); }

	private:
		T	*m_ptr;
};

#endif /* !ITERATOR_HPP */