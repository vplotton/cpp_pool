#include "Weapon.hpp"

Weapon::Weapon()
{
}

Weapon::Weapon(Weapon const & src)
{
	*this = src;
}

Weapon::~Weapon()
{
}

Weapon & Weapon::operator=(Weapon const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Weapon const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
