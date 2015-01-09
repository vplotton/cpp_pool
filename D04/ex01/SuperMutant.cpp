#include "SuperMutant.hpp"

SuperMutant::SuperMutant() : Enemy(170, "Super Mutant")
{
	std::cout << "Gaaah. Me want smash heads !" << std::endl;
}

SuperMutant::SuperMutant(SuperMutant const & src)  : Enemy(170, "Super Mutant")
{
	*this = src;
}

SuperMutant::~SuperMutant()
{
	std::cout << "Aaargh ..." << std::endl;
}

SuperMutant & SuperMutant::operator=(SuperMutant const & rhs)
{
	if (this != &rhs)
	{
		setHP(rhs.getHP());
		setType(rhs.getType());
	}
	return (*this);
}

void	SuperMutant::takeDamage(int damage)
{
	int	hpLeft = getHP() - damage - 3;

	if (damage > 0)
	{
		setHP((hpLeft > 0 ? hpLeft : 0));
	}
}

/*
std::ostream & operator<<(std::ostream & o, SuperMutant const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
*/
