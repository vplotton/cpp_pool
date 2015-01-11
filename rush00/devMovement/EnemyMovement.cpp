#include "EnemyMovement.hpp"
#include <cstdlib>
#include <ctime>

# define WIDTH 100
# define HEIGHT 100

EnemyMovement::EnemyMovement() :
	AbstractMovement(0, 0, 1)
{
	setDirection(EnemyMovement::LEFT);
	setMinX(0);
	setMinY(0);
	setMaxX(WIDTH);
	setMaxY(HEIGHT);
}

EnemyMovement::EnemyMovement(int x, int y, int speed,
		unsigned int patternSize, e_dir *& pattern) :
	AbstractMovement(x, y, speed)
{
	setPattern(pattern);
	m_patternSize = patternSize;
	m_curPatElt = 0;
	m_turn = 0;
}

EnemyMovement::EnemyMovement(EnemyMovement const & src) : AbstractMovement(src)
{
	*this = src;
}

EnemyMovement::~EnemyMovement()
{
	delete [] m_pattern;
}

EnemyMovement & EnemyMovement::operator=(EnemyMovement const & rhs)
{
	if (this != &rhs)
	{
		m_patternSize = rhs.m_patternSize;
		m_pattern = new e_dir[m_patternSize];
		for (unsigned int i = 0 ; i < m_patternSize ; ++i)
		{
			m_pattern[i] = rhs.m_pattern[i];
		}
	}
	return (*this);
}

void		EnemyMovement::setPatternSize(unsigned int patternSize)
{
	m_patternSize = patternSize;
}

void		EnemyMovement::setPattern(e_dir *& pattern)
{
	m_pattern = pattern;
}

unsigned int	EnemyMovement::getPatternSize() const
{
	return m_patternSize;
}

IMovement::e_dir		*EnemyMovement::getPattern() const
{
	return m_pattern;
}

bool	EnemyMovement::operator==(IMovement const & rhs)
{
	return (m_x == rhs.getX() && m_y == rhs.getY() ? true : false);
}

void	EnemyMovement::randMove()
{
	std::srand(time(0) * m_x * m_y * m_speed);
	int		rnd = std::rand() % 3;

	if (rnd == 0)
	{
		(m_direction == IMovement::LEFT ? goLeft() : goRight());
	}
	else if (rnd == 1)
	{
		(m_direction == IMovement::LEFT ? goLeft() : goRight());
		goDown();
	}
	else
	{
		(m_direction == IMovement::LEFT ? goLeft() : goRight());
		goUp();
	}
}

void	EnemyMovement::move(e_dir dir)
{
	(void)dir;
	if (m_turn % (m_maxSpeed - m_speed) == 0)
	{
		if (m_pattern == NULL)
		{
			randMove();
		}
		else
		{
			e_dir	currentDir = m_pattern[(m_curPatElt % m_patternSize)];
			(this->*func[currentDir])();
			(this->*func[IMovement::LEFT])();
			++m_curPatElt;
		}
	}
	++m_turn;
}

std::ostream & operator<<(std::ostream & o, EnemyMovement const & i)
{
	o << "EnemyMovement:" << std::endl
		<< "		x : " << i.getX() << std::endl
		<< "		y : " << i.getY() << std::endl
		<< "		speed : " << i.getSpeed() << std::endl
		<< "		direction : " << i.getDirName() << std::endl;
	return (o);
}
