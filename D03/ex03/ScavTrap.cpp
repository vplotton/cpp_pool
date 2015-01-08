#include "ScavTrap.hpp"
#include <cstdlib>

ScavTrap::ScavTrap() : ClapTrap()
{
	m_energyPoints = 50;
	m_maxEnergyPoints = 50;
	m_meleeAttackDamage = 20;
	m_rangedAttackDamage = 15;
	m_armorDamageReduction = 3;
	std::cout
		<< "A default SC4V-TP has been constructed, the poor robot has no name"
		<< std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	m_energyPoints = 50;
	m_maxEnergyPoints = 50;
	m_meleeAttackDamage = 20;
	m_rangedAttackDamage = 15;
	m_armorDamageReduction = 3;
	std::cout << "A SC4V-TP has been constructed, his name is " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src)
{
	m_energyPoints = 50;
	m_maxEnergyPoints = 50;
	m_meleeAttackDamage = 20;
	m_rangedAttackDamage = 15;
	m_armorDamageReduction = 3;
	std::cout << "A SC4V-TP has been copied, his name is " << m_name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "A SC4V-TP has been destructed, R.I.P " << m_name << std::endl;
}

void	ScavTrap::challengeNewcomer(std::string const & target)
{
	std::string	attackNames[5] =
	{
		" Dance, dance, baby",
		" Defeat Destroyer of Worlds",
		" Collect 139,377 brown rocks",
		" Pilfer lost staff of Mount Schuler",
		" Retrieve my grand-ma'"
	};

	if (m_energyPoints > 0)
	{
		m_energyPoints -= 25;

		std::cout << "SC4V-TP "
			<<  m_name
			<< " challenges  "
			<< target
			<< ": "
			<< attackNames[std::rand() % 5]
			<< std::endl;
	}
	else
	{
		std::cout << "There is no fun without energy!" << std::endl;
	}

}
