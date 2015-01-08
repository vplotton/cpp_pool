#include "ScavTrap.hpp"
#include <cstdlib>

ScavTrap::ScavTrap() : m_hitPoints(100),
	m_maxHitPoints(100),
	m_energyPoints(50),
	m_maxEnergyPoints(50),
	m_level(1),
	m_meleeAttackDamage(20),
	m_rangedAttackDamage(15),
	m_armorDamageReduction(3),
	m_name("")
{
	std::cout << "A default SC4V-TP has been constructed, the poor robot has no name" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : m_hitPoints(100),
	m_maxHitPoints(100),
	m_energyPoints(50),
	m_maxEnergyPoints(50),
	m_level(1),
	m_meleeAttackDamage(20),
	m_rangedAttackDamage(15),
	m_armorDamageReduction(3),
	m_name(name)
{
	std::cout << "A SC4V-TP has been constructed, his name is " << name << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src) : m_hitPoints(100),
	m_maxHitPoints(100),
	m_energyPoints(50),
	m_maxEnergyPoints(50),
	m_level(1),
	m_meleeAttackDamage(20),
	m_rangedAttackDamage(15),
	m_armorDamageReduction(3),
	m_name("")
{
	*this = src;
	std::cout << "A SC4V-TP has been copied, his name is " << m_name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "A SC4V-TP has been destructed, R.I.P " << m_name << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & rhs)
{
	if (this != &rhs)
	{

		std::cout << "You assigned me?? You really did that?? 'kay!" << std::endl;
		/* my implementation, don't forget to change this. */
	}
	return (*this);
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

void	ScavTrap::rangedAttack(std::string const & target)
{
	std::cout << "SC4V-TP "
		<< m_name
		<< " attacks "
		<< target
		<< " at range, causing "
		<< m_rangedAttackDamage
		<< " points of damage !"
		<< std::endl;
}

void	ScavTrap::meleeAttack(std::string const & target)
{
	std::cout << "SC4V-TP "
		<< m_name
		<< " attacks "
		<< target
		<< " at melee, causing "
		<< m_meleeAttackDamage
		<< " points of damage !"
		<< std::endl;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	unsigned int damageTaken;

	damageTaken = (amount > m_armorDamageReduction ?
			amount - m_armorDamageReduction : 0);


	if (damageTaken > m_hitPoints)
	{
		std::cout << "Oh... sh!t..." << std::endl;
	}
	else if (damageTaken > 0)
	{
		m_hitPoints -= damageTaken;
		std::cout << "HELP! HELP! I'M HURT! I TOOK "
			<< damageTaken
			<< " DAMAGE IN THE FACE!"
			<< std::endl;
	}
	else
	{
		std::cout << "I TOOK NO DAMAGE!!!" << std::endl;
	}
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (amount + m_hitPoints > m_maxHitPoints)
	{
		m_hitPoints = m_maxHitPoints;
		std::cout << "I FEEEEEEL GOOOD! LALALALALAAAAAA! SO GOOD! SO GOOD! I GOT YOU!" << std::endl;
	}
	else
	{
		m_hitPoints += amount;
		std::cout << "WOW! THX BUDDY!" << std::endl;
	}
}

/*
   std::ostream & operator<<(std::ostream & o, ScavTrap const & i)
   {
   o << "You. Better. Watch out!";
   return (o);
   }
   */
