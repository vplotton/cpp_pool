#include "Display.hpp"

Display::Display()
{
}

Display::Display(Display const & src)
{
	*this = src;
}

Display::~Display()
{
}

Display & Display::operator=(Display const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Display const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
