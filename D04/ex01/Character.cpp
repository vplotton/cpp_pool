#include "Character.hpp"

Character::Character() : m_name(""), m_actionPoints(40), m_weapon(NULL)
{
}

Character::Character(std::string name) : m_name(name), m_actionPoints(40), m_weapon(NULL)
{
}

Character::Character(Character const & src) : m_name(""), m_actionPoints(40), m_weapon(NULL)
{
	*this = src;
}

Character::~Character()
{
}

Character & Character::operator=(Character const & rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_actionPoints = rhs.m_actionPoints;
		m_weapon = rhs.m_weapon;
	}
	return (*this);
}

void	Character::recoverAP()
{
	int	actionPointsAfter = m_actionPoints + 10;

	m_actionPoints = (actionPointsAfter > 40 ? 40 : actionPointsAfter);
}

void	Character::equip(AWeapon *weapon)
{
	m_weapon = weapon;
}

void	Character::attack(Enemy *enemy)
{
	if (m_weapon != NULL)
	{
		int	actionPointsLeft = m_actionPoints - m_weapon->getAPCost();
		if (actionPointsLeft > 0)
		{
			std::cout << m_name
				<< " attacks "
				<< enemy->getType()
				<< " with a "
				<< m_weapon->getName()
				<< std::endl;

			m_actionPoints = actionPointsLeft;
			enemy->takeDamage(m_weapon->getDamage());
		}
	}
	else
	{
		std::cout << "You have no weapon to attack with." << std::endl;
	}
}

std::string const	&Character::getName() const
{
	return m_name;
}

AWeapon			*Character::getWeapon() const
{
	return m_weapon;
}

int			Character::getAP() const
{
	return m_actionPoints;
}

std::ostream & operator<<(std::ostream & o, Character const & i)
{
	AWeapon		*weapon = i.getWeapon();
	std::string	weaponName = (weapon == NULL ? "* no weapon *" : weapon->getName());

	o << i.getName() << " has " << i.getAP() << " AP and wields a " << weaponName << std::endl;
	return (o);
}
