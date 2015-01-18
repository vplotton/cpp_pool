#ifndef WEAPON_HPP
# define WEAPON_HPP

#include "Projectile.hpp"
#include <iostream>
#include <string>

class Weapon
{
	public:
		Weapon();
		Weapon(unsigned int, std::string);
		Weapon(Weapon const & src);
		~Weapon();

		Weapon & operator=(Weapon const & rhs);

		void	setDamage(unsigned int const &dmg);
		void	setName(std::string const &name);
		unsigned int	getDamage() const;
		std::string		getName() const;

		AbstractObject	*shoot(IMovement const *);

	private:
		unsigned int	m_damage;
		std::string		m_name;
};

std::ostream & operator<<(std::ostream & o, Weapon const & i);

#endif /* !WEAPON_HPP */
