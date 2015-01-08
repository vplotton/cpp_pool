#include "FragTrap.hpp"
#include <cstdlib>

FragTrap::FragTrap() : m_hitPoints(100),
	m_maxHitPoints(100),
	m_energyPoints(100),
	m_maxEnergyPoints(100),
	m_level(1),
	m_meleeAttackDamage(30),
	m_rangedAttackDamage(20),
	m_armorDamageReduction(5),
	m_name("")
{
	std::cout << "A default FR4G-TP has been constructed, the poor robot has no name" << std::endl;
}

FragTrap::FragTrap(std::string name) : m_hitPoints(100),
	m_maxHitPoints(100),
	m_energyPoints(100),
	m_maxEnergyPoints(100),
	m_level(1),
	m_meleeAttackDamage(30),
	m_rangedAttackDamage(20),
	m_armorDamageReduction(5),
	m_name(name)
{
	std::cout << "A FR4G-TP has been constructed, his name is " << name << std::endl;
}

FragTrap::FragTrap(FragTrap const & src) : m_hitPoints(100),
	m_maxHitPoints(100),
	m_energyPoints(100),
	m_maxEnergyPoints(100),
	m_level(1),
	m_meleeAttackDamage(30),
	m_rangedAttackDamage(20),
	m_armorDamageReduction(5),
	m_name("")
{
	*this = src;
	std::cout << "A FR4G-TP has been copied, his name is " << m_name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "A FR4G-TP has been destructed, R.I.P " << m_name << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & rhs)
{
	if (this != &rhs)
	{
		std::cout << "You assigned me?? You really did that?? 'kay!" << std::endl;
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

void	FragTrap::vaulthunter_dot_exe(std::string const & target)
{
	std::string	attackNames[5] =
	{
		" at range with spoons",
		" at melee with a sniper",
		" it throws Justin Bieber tickets at him",
		" explodes on him",
		" can't stop shoooottiiiiiing"
	};

	if (m_energyPoints > 0)
	{
		m_energyPoints -= 25;

		std::cout << "FR4G-TP "
			<<  m_name
			<< " attacks "
			<< target
			<< attackNames[std::rand() % 5]
			<< std::endl;
	}
	else
	{
		std::cout << "There is no fun without energy!" << std::endl;
	}

}

void	FragTrap::rangedAttack(std::string const & target)
{
	std::cout << "FR4G-TP "
		<< m_name
		<< " attacks "
		<< target
		<< " at range, causing "
		<< m_rangedAttackDamage
		<< " points of damage !"
		<< std::endl;
}

void	FragTrap::meleeAttack(std::string const & target)
{
	std::cout << "FR4G-TP "
		<< m_name
		<< " attacks "
		<< target
		<< " at melee, causing "
		<< m_meleeAttackDamage
		<< " points of damage !"
		<< std::endl;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	unsigned int damageTaken;

	damageTaken = (amount > m_armorDamageReduction ?
			amount - m_armorDamageReduction : 0);

	if (damageTaken > m_hitPoints)
	{
		m_hitPoints = 0;
		std::cout << "Oh... sh!t..." << std::endl;
	}
	else if (damageTaken > 0)
	{
		m_hitPoints -= damageTaken;
		std::cout << "HELP! HELP! I'M HURT! I TOOK "
			<< damageTaken
			<< " IN THE FACE!"
			<< std::endl;
	}
	else
	{
		std::cout << "I TOOK NO DAMAGE!!!" << std::endl
	}
}

void	FragTrap::beRepaired(unsigned int amount)
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


std::ostream & operator<<(std::ostream & o, FragTrap const & i)
{
	o << "You. Better. Watch out!";
	return (o);
}
