#include "SpaceShip.hpp"

SpaceShip::SpaceShip() : 
	AbstractObject(AbstractObject::SPACESHIP, 1, 0, 0)
{
	m_title = std::string("");
	m_weapon = new Weapon;
}

SpaceShip::SpaceShip(std::string title, unsigned int life, int x, int y) :
	AbstractObject(AbstractObject::SPACESHIP, life, x, y)
{
	m_title = title;
	m_weapon = new Weapon;
}

SpaceShip::SpaceShip(SpaceShip const & src) :
	AbstractObject(AbstractObject::SPACESHIP, 1, 0, 0)
{
	*this = src;
}

SpaceShip::~SpaceShip()
{
	delete m_weapon;
}

SpaceShip & SpaceShip::operator=(SpaceShip const & rhs)
{
	if (this != &rhs)
	{
		m_title = rhs.m_title;
		m_weapon = new Weapon(*rhs.m_weapon);
	}
	return (*this);
}

void		SpaceShip::setTitle(std::string const & title)
{
	m_title = title;
}

void		SpaceShip::setWeapon(Weapon * &weapon)
{
	m_weapon = weapon;
}

std::string	SpaceShip::getTitle() const
{
	return m_title;
}

Weapon		*SpaceShip::getWeapon() const
{
	return m_weapon;
}

std::ostream & operator<<(std::ostream & o, SpaceShip const & i)
{
	o << "Object - [ type : " << i.getType()
		<< " ] - [ name : " << i.getName()
		<< " ] - [ title : " << i.getTitle()
		<< " ] [ life : " << i.getLife()
		<< " ]" << std::endl;
	return (o);
}
