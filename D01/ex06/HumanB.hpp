#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB
{
	public:
		HumanB(std::string name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon weapon);

	private:
		Weapon		*m_weapon;
		std::string	m_name;
};

#endif /* ~HUMANB_HPP */
