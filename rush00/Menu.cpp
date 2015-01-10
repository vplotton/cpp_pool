#include "Menu.hpp"

Menu::Menu()
{
}

Menu::Menu(Menu const & src)
{
	*this = src;
}

Menu::~Menu()
{
}

Menu & Menu::operator=(Menu const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Menu const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
