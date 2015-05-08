#include "Square.hpp"

Square  Square::null(-1, -1, -1);

Square::Square() :
	m_x(0)
	, m_y(0)
	, m_liberties(4)
{
}

Square::Square(int x, int y, int liberties):
	m_x(x)
	, m_y(y)
	, m_liberties((liberties < 5 && liberties > -1 ? liberties : -1)) 
{
}

Square::Square(Square const & src)
{
	*this = src;
}

Square::~Square()
{
}

Square & Square::operator=(Square const & rhs)
{
	if (this != &rhs)
	{
		m_x = rhs.m_x;
		m_y = rhs.m_y;
		m_liberties = rhs.m_liberties;
	}
	return (*this);
}

int const	&Square::x() const
{
	return m_x;
}

int const	&Square::y() const
{
	return m_y;
}

int const	&Square::liberties() const
{
	return m_liberties;
}


void		Square::x(int const &x)
{
	m_x = x;
}

void		Square::y(int const &y)
{
	m_y = y;
}

void		Square::liberties(int const &liberties)
{
	m_liberties = liberties;
}

std::ostream & operator<<(std::ostream & o, Square const & i)
{
	o << "[ Square ]"
		<< "\n	x: " << i.x()
		<< "\n	y: " << i.y()
		<< "\n	liberties: " << i.liberties()
		<< std::endl;
	return (o);
}
