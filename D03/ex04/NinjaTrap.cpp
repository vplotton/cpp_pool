#include "NinjaTrap.hpp"
#include <cstdlib>

NinjaTrap::NinjaTrap() : ClapTrap()
{
	m_hitPoints = 60;
	m_maxHitPoints = 60;
	m_energyPoints = 120;
	m_maxEnergyPoints = 120;
	m_meleeAttackDamage = 60;
	m_rangedAttackDamage = 5;
	m_armorDamageReduction = 0;
	std::cout
		<< "A default NINJ4-TP has been constructed, the poor robot has no name"
		<< std::endl;
}

NinjaTrap::NinjaTrap(std::string name) : ClapTrap(name)
{
	m_hitPoints = 60;
	m_maxHitPoints = 60;
	m_energyPoints = 120;
	m_maxEnergyPoints = 120;
	m_meleeAttackDamage = 60;
	m_rangedAttackDamage = 5;
	m_armorDamageReduction = 0;
	std::cout << "A NINJ4-TP has been constructed, his name is " << name << std::endl;
}

NinjaTrap::NinjaTrap(NinjaTrap const & src) : ClapTrap(src)
{
	m_hitPoints = 60;
	m_maxHitPoints = 60;
	m_energyPoints = 120;
	m_maxEnergyPoints = 120;
	m_meleeAttackDamage = 60;
	m_rangedAttackDamage = 5;
	m_armorDamageReduction = 0;
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
