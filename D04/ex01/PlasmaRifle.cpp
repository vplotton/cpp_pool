#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle" , 21, 5)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) : AWeapon("Plasma Rifle" , 21, 5)
{
	*this = src;
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

void	PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}

/*
std::ostream & operator<<(std::ostream & o, PlasmaRifle const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
*/
