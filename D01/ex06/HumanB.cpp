#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : m_name(name), m_weapon(NULL)
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	std::cout << m_name << " attacks with his " << m_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	m_weapon = &weapon;
}
