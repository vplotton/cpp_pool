#include "Movement.hpp"

Movement::Movement() : m_x(0), m_y(0), m_speed(0)
{
}

Movement::Movement(int x, int y, int speed) : m_x(x), m_y(y), m_speed(speed)
{
}

Movement::Movement(Movement const & src) : m_x(0), m_y(0), m_speed(0)
{
	*this = src;
}

Movement::~Movement()
{
	m_x = 0;
	m_y = 0;
	m_speed = 0;
}

Movement & Movement::operator=(Movement const & rhs)
{
	if (this != &rhs)
	{
		m_x = rhs.m_x;
		m_y = rhs.m_y;
		m_speed = rhs.m_speed;
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

void	Movement::setSpeed(int const & speed)
{
	m_speed = speed;
}

int		Movement::getX() const
{
	return m_x;
}

int		Movement::getY() const
{
	return m_y;
}

int		Movement::getSpeed() const
{
	return m_speed;
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
	o << "Movement:" << std::endl
		<< "		x : " << i.getX() << std::endl
		<< "		y : " << i.getY() << std::endl
		<< "		speed : " << i.getSpeed() << std::endl;
	return (o);
}
