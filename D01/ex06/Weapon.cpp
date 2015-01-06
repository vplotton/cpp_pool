#include "Weapon.hpp"

Weapon::Weapon(std::string type) : m_type(type)
{
}

Weapon::~Weapon()
{
}

void	Weapon::setType(std::string type)
{
	m_type = type;
}

std::string	Weapon::getType()
{
	return (m_type);
}
