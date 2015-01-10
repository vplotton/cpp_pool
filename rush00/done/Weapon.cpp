#include "Weapon.hpp"

Weapon::Weapon() : m_damage(0), m_name("")
{
}

Weapon::Weapon(unsigned int damage, std::string name) :
	m_damage(damage), m_name(name)
{
}

Weapon::Weapon(Weapon const & src) : m_damage(0), m_name("")
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
		m_damage = rhs.m_damage;
		m_name = rhs.m_name;
	}
	return (*this);
}

void	Weapon::setDamage(unsigned int const & damage)
{
	m_damage = damage;
}

void	Weapon::setName(std::string const & name)
{
	m_name = name;
}

unsigned int	Weapon::getDamage() const
{
	return m_damage;
}

std::string		Weapon::getName() const
{
	return m_name;
}

Projectile		*Weapon::shoot(int x, int y)
{
	Projectile	*newProjectile = new Projectile(x, y);

	return newProjectile;
}

std::ostream & operator<<(std::ostream & o, Weapon const & i)
{
	o << "Weapon - [ name : " << i.getName()
		<< " ] [ damage : " << i.getDamage()
		<< " ]" << std::endl;
	return (o);
}