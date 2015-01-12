#include "AbstractMovement.hpp"

# define WIDTH  98
# define HEIGHT 48

typedef  void (AbstractMovement::*Func)();

std::string const AbstractMovement::typeDirNames[] =
{
	"UP",
	"DOWN",
	"LEFT",
	"RIGHT"
};

const unsigned int	AbstractMovement::m_maxSpeed = 10;

Func AbstractMovement::func[] = 
{
	&AbstractMovement::goUp,
	&AbstractMovement::goDown,
	&AbstractMovement::goLeft,
	&AbstractMovement::goRight
};

AbstractMovement::AbstractMovement() : 
	m_x(0), m_y(0), m_speed(0)
{
	setDirection(AbstractMovement::LEFT);
	setMinX(0);
	setMinY(0);
	setMaxX(WIDTH);
	setMaxY(HEIGHT);
}

AbstractMovement::AbstractMovement(int x, int y, unsigned int speed) :
	m_x(x), m_y(y), m_speed((speed  < m_maxSpeed ? speed : m_maxSpeed - 1))
{
	setDirection(AbstractMovement::LEFT);
	setMinX(0);
	setMinY(0);
	setMaxX(WIDTH);
	setMaxY(HEIGHT);
}

AbstractMovement::AbstractMovement(AbstractMovement const & src) :
	m_x(0), m_y(0), m_speed(0)
{
	setDirection(AbstractMovement::LEFT);
	setMinX(0);
	setMinY(0);
	setMaxX(WIDTH);
	setMaxY(HEIGHT);
	*this = src;
}

AbstractMovement::~AbstractMovement()
{
	m_x = 0;
	m_y = 0;
	m_speed = 0;
}

AbstractMovement & AbstractMovement::operator=(AbstractMovement const & rhs)
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

bool	AbstractMovement::operator==(IMovement const & rhs)
{
	return (m_x == rhs.getX() && m_y == rhs.getY() ? true : false);
}

void	AbstractMovement::setX(int const & x)
{
	m_x = x;
}

void	AbstractMovement::setY(int const & y)
{
	m_y = y;
}

void	AbstractMovement::setMinX(int const & minX)
{
	m_minX = minX;
}

void	AbstractMovement::setMinY(int const & minY)
{
	m_minY = minY;
}

void	AbstractMovement::setMaxX(int const & maxX)
{
	m_maxX = maxX;
}

void	AbstractMovement::setMaxY(int const & maxY)
{
	m_maxY = maxY;
}

void	AbstractMovement::setSpeed(int const & speed)
{
	m_speed = speed;
}

void	AbstractMovement::setDirection(e_dir const & direction)
{
	m_direction = direction;
	m_dirName = typeDirNames[(int)direction];
}

int		AbstractMovement::getX() const
{
	return m_x;
}

int		AbstractMovement::getY() const
{
	return m_y;
}

int		AbstractMovement::getMinX() const
{
	return m_minX;
}

int		AbstractMovement::getMinY() const
{
	return m_minY;
}

int		AbstractMovement::getMaxX() const
{
	return m_maxX;
}

int		AbstractMovement::getMaxY() const
{
	return m_maxY;
}

int		AbstractMovement::getSpeed() const
{
	return m_speed;
}

AbstractMovement::e_dir	AbstractMovement::getDirection() const
{
	return m_direction;
}

std::string		AbstractMovement::getDirName() const
{
	return m_dirName;
}

bool	AbstractMovement::checkLimits() const
{
	if (getX() <= m_minX || getX() >= m_maxX || getY() <= m_minY || getY() >= m_maxX)
	{
		return true;
	}
	return false;
}

void	AbstractMovement::goUp()
{
	if (m_y - 1 >= m_minY)
	{
		--m_y;
	}
}

void    AbstractMovement::goDown()
{
	if (m_y + 1 <= m_maxY)
	{
		++m_y;
	}
}

void    AbstractMovement::goLeft()
{
	if (m_x - 1 >= m_minX)
	{
		--m_x;
	}
}

void    AbstractMovement::goRight()
{
	if (m_x + 1 <= m_maxX)
	{
		++m_x;
	}
}

void	AbstractMovement::goForward()
{
	(m_direction == LEFT ? goLeft() : goRight());
}

std::ostream & operator<<(std::ostream & o, AbstractMovement const & i)
{
	o << "AbstractMovement:" << std::endl
		<< "		x : " << i.getX() << std::endl
		<< "		y : " << i.getY() << std::endl
		<< "		speed : " << i.getSpeed() << std::endl
		<< "		direction : " << i.getDirName() << std::endl;
	return (o);
}
