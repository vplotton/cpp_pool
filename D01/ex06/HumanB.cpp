#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : m_name(name), m_weapon(new Weapon(""))
{
}

HumanB::~HumanB()
{
}

void	HumanB::attack()
{
	std::cout << m_name << " attacks with " << m_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon weapon)
{
	delete m_weapon;
	m_weapon = &weapon;
}
