#include "SuperTrap.hpp"

unsigned int	max(unsigned int a, unsigned int b)
{
	return ((a > b ? a : b));
}

SuperTrap::SuperTrap() : ClapTrap(), NinjaTrap(), FragTrap()
{
	m_rangedAttackDamage = max(FragTrap::m_rangedAttackDamage, NinjaTrap::m_rangedAttackDamage);
	m_meleeAttackDamage = max(FragTrap::m_meleeAttackDamage, NinjaTrap::m_meleeAttackDamage);

	std::cout
		<< "A default SUP3R-TP has been constructed, the poor robot has no name"
		<< std::endl;
}

SuperTrap::SuperTrap(std::string name) : ClapTrap(name), NinjaTrap(name), FragTrap(name)
{
	std::cout << "A SUP3R-TP has been constructed, his name is "
		<< m_name << std::endl;
}

SuperTrap::SuperTrap(SuperTrap const & src) : ClapTrap(src), NinjaTrap(src), FragTrap(src)
{
	std::cout
		<< "A SUP3R-TP has been copied, his name is "
		<< m_name << std::endl;
}

SuperTrap::~SuperTrap()
{
	std::cout << "A SUP3R-TP has been destructed, R.I.P " << m_name << std::endl;
}
