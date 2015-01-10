#include "Spaceship.hpp"

Spaceship::Spaceship()
{
}

Spaceship::Spaceship(Spaceship const & src)
{
	*this = src;
}

Spaceship::~Spaceship()
{
}

Spaceship & Spaceship::operator=(Spaceship const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Spaceship const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
