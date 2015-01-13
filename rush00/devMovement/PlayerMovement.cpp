#include "PlayerMovement.hpp"

# define WIDTH  98
# define HEIGHT 48

PlayerMovement::PlayerMovement() :
	AbstractMovement(0, 0, 1)
{
}

PlayerMovement::PlayerMovement(int x, int y) :
	AbstractMovement(x, y, 1)
{
}

PlayerMovement::PlayerMovement(PlayerMovement const & src) : AbstractMovement(src)
{
	*this = src;
}

PlayerMovement::~PlayerMovement()
{
}

PlayerMovement & PlayerMovement::operator=(PlayerMovement const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

bool	PlayerMovement::operator==(IMovement const & rhs)
{
	return (m_x == rhs.getX() && m_y == rhs.getY() ? true : false);
}

void	PlayerMovement::move(e_dir dir)
{
	if ((int)dir < 4 && (int)dir > - 1)
	{
		(this->*func[dir])();
	}
}

std::ostream & operator<<(std::ostream & o, PlayerMovement const & i)
{
	o << "PlayerMovement:" << std::endl
		<< "		x : " << i.getX() << std::endl
		<< "		y : " << i.getY() << std::endl
		<< "		speed : " << i.getSpeed() << std::endl
		<< "		direction : " << i.getDirName() << std::endl;
	return (o);
}
