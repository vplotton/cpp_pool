#include "ClapTrap.hpp"
#include <cstdlib>

ClapTrap::ClapTrap() : m_hitPoints(100),
	m_maxHitPoints(100),
	m_maxEnergyPoints(100),
	m_level(1),
	m_meleeAttackDamage(30),
	m_rangedAttackDamage(20),
	m_armorDamageReduction(5),
	m_energyPoints(100),
	m_name("")
{
	std::cout << "A default CL4P-TP has been constructed, the poor robot has no name" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : m_hitPoints(100),
	m_maxHitPoints(100),
	m_maxEnergyPoints(100),
	m_level(1),
	m_meleeAttackDamage(30),
	m_rangedAttackDamage(20),
	m_armorDamageReduction(5),
	m_energyPoints(100),
	m_name(name)
{
	std::cout << "A CL4P-TP has been constructed, his name is " << name << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const & src) : m_hitPoints(100),
	m_maxHitPoints(100),
	m_maxEnergyPoints(100),
	m_level(1),
	m_meleeAttackDamage(30),
	m_rangedAttackDamage(20),
	m_armorDamageReduction(5),
	m_energyPoints(100),
	m_name("")
{
	*this = src;
	std::cout << "A CL4P-TP has been copied, his name is " << m_name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "A CL4P-TP has been destructed, R.I.P " << m_name << std::endl;
}

ClapTrap & ClapTrap::operator=(ClapTrap const & rhs)
{
	if (this != &rhs)
	{
		std::cout << "You assigned me?? You really did that?? 'kay!" << std::endl;
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

void	ClapTrap::rangedAttack(std::string const & target)
{
	std::cout << "CL4P-TP "
		<< m_name
		<< " attacks "
		<< target
		<< " at range, causing "
		<< m_rangedAttackDamage
		<< " points of damage !"
		<< std::endl;
}

void	ClapTrap::meleeAttack(std::string const & target)
{
	std::cout << "CL4P-TP "
		<< m_name
		<< " attacks "
		<< target
		<< " at melee, causing "
		<< m_meleeAttackDamage
		<< " points of damage !"
		<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int damageTaken;

	damageTaken = (amount > m_armorDamageReduction ?
			amount - m_armorDamageReduction : 0);

	if (damageTaken > m_hitPoints)
	{
		m_hitPoints = 0;
		std::cout << "Oh... sh!t..." << std::endl;
		/* should destruct here */
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

void	ClapTrap::beRepaired(unsigned int amount)
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
std::ostream & operator<<(std::ostream & o, ClapTrap const & i)
{
	o << "You. Better. Watch out!";
	return (o);
}
*/
