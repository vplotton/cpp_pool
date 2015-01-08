#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include <iostream>
#include <string>

class ScavTrap
{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		~ScavTrap();

		ScavTrap & operator=(ScavTrap const & rhs);

		void	vaulthunter_dot_exe(std::string const & target);
		void	rangedAttack(std::string const & target);
		void	meleeAttack(std::string const & target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);

	private:
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

std::ostream & operator<<(std::ostream & o, ScavTrap const & i);

#endif /* !FRAGTRAP_HPP */
