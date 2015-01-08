#include "NinjaTrap.hpp"
#include <cstdlib>

void		NinjaTrap::setMembers()
{
	m_hitPoints = (!m_hitPoints || m_hitPoints < 60 ? 60 : m_hitPoints);
	m_maxHitPoints = m_hitPoints;
	m_energyPoints = (!m_energyPoints || m_energyPoints < 120 ? 120 : m_energyPoints);
	m_maxEnergyPoints = m_energyPoints;
	m_meleeAttackDamage = (!m_meleeAttackDamage || m_meleeAttackDamage < 60 ? 60 : m_meleeAttackDamage);
	m_rangedAttackDamage = (!m_rangedAttackDamage || m_rangedAttackDamage < 5 ? 5 : m_rangedAttackDamage);
	m_armorDamageReduction = (!m_armorDamageReduction || m_armorDamageReduction <= 0 ? 0 : m_armorDamageReduction);
}

NinjaTrap::NinjaTrap() : ClapTrap()
{
	setMembers();
	std::cout
		<< "A default NINJ4-TP has been constructed, the poor robot has no name"
		<< std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	setMembers();
	std::cout << "A NINJ4-TP has been constructed, his name is " << name << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src)
{
	setMembers();
	std::cout << "A NINJ4-TP has been copied, his name is " << m_name << std::endl;
}

NinjaTrap::~NinjaTrap()
{
	std::cout << "A NINJ4-TP has been destructed, R.I.P " << m_name << std::endl;
}

void	NinjaTrap::healNoob(std::string const & target) const
{
	std::string	attackNames[5] =
	{
		" With a spoon",
		" Throws a grenade at him",
		" \"LET THE ROCKS FAAAAALL\"",
		" \"I dance, you dance, everybody dance!!\"",
		" Gives him a kiss"
	};

	if (m_energyPoints > 0)
	{
		m_energyPoints -= 25;

		std::cout << "NINJ4-TP "
			<<  m_name
			<< " heals  "
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

void	NinjaTrap::ninjaShoebox(FragTrap const & trap, std::string const target)
{
	trap.vaulthunter_dot_exe(target);
}

void	NinjaTrap::ninjaShoebox(ScavTrap const & trap, std::string const target)
{
	trap.challengeNewcomer(target);
}

void	NinjaTrap::ninjaShoebox(NinjaTrap const & trap, std::string const target)
{
	trap.healNoob(target);
}
