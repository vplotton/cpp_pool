#include "Interact.hpp"

Interact::Interact()
{
}

Interact::Interact(Interact const & src)
{
	*this = src;
}

Interact::~Interact()
{
}

Interact & Interact::operator=(Interact const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Interact const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
