#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const & src);
		~ClapTrap();

		ClapTrap & operator=(ClapTrap const & rhs);

		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	protected:
		unsigned int	m_hitPoints;
		unsigned int	m_maxHitPoints;
		unsigned int	m_energyPoints;
		unsigned int	m_maxEnergyPoints;
		unsigned int	m_level;
		unsigned int	m_meleeAttackDamage;
		unsigned int	m_rangedAttackDamage;
		unsigned int	m_armorDamageReduction;
		std::string	m_name;

};

/*std::ostream & operator<<(std::ostream & o, ClapTrap const & i);*/

#endif /* !CLAPTRAP_HPP */
