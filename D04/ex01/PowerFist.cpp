#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 50, 8)
{
}

PowerFist::PowerFist(PowerFist const & src) : AWeapon("Power Fist", 50, 8)
{
	*this = src;
}

PowerFist::~PowerFist()
{
}

PowerFist & PowerFist::operator=(PowerFist const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}

/*
std::ostream & operator<<(std::ostream & o, PowerFist const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
*/
