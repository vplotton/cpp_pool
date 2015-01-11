#include "Movement.hpp"

std::string const Movement::typeDirNames[] =
{
	"UP",
	"DOWN",
	"LEFT",
	"RIGHT"
};

Movement::Movement() : 
	m_x(0), m_y(0), m_speed(0)
{
	setDirection(Movement::LEFT);
}

Movement::Movement(int x, int y, int speed) :
	m_x(x), m_y(y), m_speed(speed)
{
	setDirection(Movement::LEFT);
}

Movement::Movement(Movement const & src) :
	m_x(0), m_y(0), m_speed(0), m_direction(Movement::LEFT)
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
		setDirection(rhs.m_direction);
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

void	Movement::setDirection(e_dir const & direction)
{
	m_direction = direction;
	m_dirName = typeDirNames[(int)direction];
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

Movement::e_dir	Movement::getDirection() const
{
	return m_direction;
}

std::string		Movement::getDirName() const
{
	return m_dirName;
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
		<< "		speed : " << i.getSpeed() << std::endl
		<< "		direction : " << i.getDirName() << std::endl;
	return (o);
}
