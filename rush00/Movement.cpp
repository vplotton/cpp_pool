#include "Movement.hpp"

Movement::Movement()
{
}

Movement::Movement(Movement const & src)
{
	*this = src;
}

Movement::~Movement()
{
}

Movement & Movement::operator=(Movement const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Movement const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
