#include "FragTrap.hpp"
#include <cstdlib>

FragTrap::FragTrap() : ClapTrap()
{
	std::cout
		<< "A default FR4G-TP has been constructed, the poor robot has no name"
		<< std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src)
{
	std::cout
		<< "A FR4G-TP has been copied, his name is "
		<< m_name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "A FR4G-TP has been destructed, R.I.P " << m_name << std::endl;
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
