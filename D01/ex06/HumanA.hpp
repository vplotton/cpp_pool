#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA
{
	public:
		HumanA(std::string name, Weapon weapon);
		~HumanA();
		void attack();

	private:
		Weapon		m_weapon;
		std::string	m_name;
};

#endif /* !HUMANA_HPP */
