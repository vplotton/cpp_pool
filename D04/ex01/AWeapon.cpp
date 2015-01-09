#include "AWeapon.hpp"

AWeapon::AWeapon() : m_name(""), m_actionPoints(0), m_attackDamage(0)
{
}

AWeapon::AWeapon(std::string const & name, int apcost, int damage) : m_name(name), m_actionPoints(apcost), m_attackDamage(damage)
{
}

AWeapon::AWeapon(AWeapon const & src) : m_name(""), m_actionPoints(0), m_attackDamage(0)
{
	*this = src;
}

AWeapon::~AWeapon()
{
}

AWeapon & AWeapon::operator=(AWeapon const & rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_actionPoints = rhs.m_actionPoints;
		m_attackDamage = rhs.m_attackDamage;
	}
	return (*this);
}

std::string	AWeapon::getName() const
{
	return m_name;
}

int		AWeapon::getAPCost() const
{
	return m_actionPoints;
}

int		AWeapon::getDamage() const
{
	return m_attackDamage;
}

/*
std::ostream & operator<<(std::ostream & o, AWeapon const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
*/
