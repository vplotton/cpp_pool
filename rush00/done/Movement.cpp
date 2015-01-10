#include "Movement.hpp"

Movement::Movement() : m_x(0), m_y(0)
{
}

Movement::Movement(int x, int y) : m_x(x), m_y(y)
{
}

Movement::Movement(Movement const & src) : m_x(0), m_y(0)
{
	*this = src;
}

Movement::~Movement()
{
	m_x = 0;
	m_y = 0;
}

Movement & Movement::operator=(Movement const & rhs)
{
	if (this != &rhs)
	{
		m_x = rhs.m_x;
		m_y = rhs.m_y;
	}
	return (*this);
}

void	Movement::setX(int const & x)
{
	m_x = x;
}

void	Movement::setY(int const & y)
{
	m_y = y;
}

int		Movement::getX() const
{
	return m_x;
}

int		Movement::getY() const
{
	return m_y;
}

void	Movement::goUp()
{
	--m_y;
}

void    Movement::goDown()
{
	++m_y;
}

void    Movement::goLeft()
{
	--m_x;
}

void    Movement::goRight()
{
	++m_x;
}

std::ostream & operator<<(std::ostream & o, Movement const & i)
{
	o << "Movement - [ x : " << i.getX()
		<< " ] [ y : " << i.getY()
		<< " ]" << std::endl;
	return (o);
}
