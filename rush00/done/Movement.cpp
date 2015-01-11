#include "Movement.hpp"
#include <cstdlib>
#include <ctime>

std::string const Movement::typeDirNames[] =
{
	"UP",
	"DOWN",
	"LEFT",
	"RIGHT"
};

# define WIDTH 100
# define HEIGHT 100

Movement::Movement() : 
	m_x(0), m_y(0), m_speed(0)
{
	setDirection(Movement::LEFT);
	setMinX(0);
	setMinY(0);
	setMaxX(WIDTH);
	setMaxY(HEIGHT);
}

Movement::Movement(int x, int y, int speed) :
	m_x(x), m_y(y), m_speed(speed)
{
	setDirection(Movement::LEFT);
	setMinX(0);
	setMinY(0);
	setMaxX(WIDTH);
	setMaxY(HEIGHT);
}

Movement::Movement(Movement const & src) :
	m_x(0), m_y(0), m_speed(0)
{
	setDirection(Movement::LEFT);
	setMinX(0);
	setMinY(0);
	setMaxX(WIDTH);
	setMaxY(HEIGHT);
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

bool	Movement::operator==(Movement const & rhs)
{
	return (m_x == rhs.m_x && m_y == rhs.m_y ? true : false);
}

void	Movement::setX(int const & x)
{
	m_x = x;
}

void	Movement::setY(int const & y)
{
	m_y = y;
}

void	Movement::setMinX(int const & minX)
{
	m_minX = minX;
}

void	Movement::setMinY(int const & minY)
{
	m_minY = minY;
}

void	Movement::setMaxX(int const & maxX)
{
	m_maxX = maxX;
}

void	Movement::setMaxY(int const & maxY)
{
	m_maxY = maxY;
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

int		Movement::getMinX() const
{
	return m_minX;
}

int		Movement::getMinY() const
{
	return m_minY;
}

int		Movement::getMaxX() const
{
	return m_maxX;
}

int		Movement::getMaxY() const
{
	return m_maxY;
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
	if (m_y - 1 > m_minY)
	{
		--m_y;
	}
}

void    Movement::goDown()
{
	if (m_y + 1 < m_maxY)
	{
		++m_y;
	}
}

void    Movement::goLeft()
{
	if (m_x - 1 > m_minX)
	{
		--m_x;
	}
}

void    Movement::goRight()
{
	if (m_x + 1 < m_maxX)
	{
		++m_x;
	}
}

void	Movement::goForward()
{
	(m_direction == LEFT ? goLeft() : goRight());
}

void	Movement::randMove()
{
	std::srand(time(0) * m_x * m_y * m_speed);
	int		rnd = std::rand() % 3;

	if (rnd == 0)
	{
		(m_direction == LEFT ? goLeft() : goRight());
	}
	else if (rnd == 1)
	{
		(m_direction == LEFT ? goLeft() : goRight());
		goDown();
	}
	else
	{
		(m_direction == LEFT ? goLeft() : goRight());
		goUp();
	}
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
