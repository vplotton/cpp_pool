#ifndef SPACESHIP_HPP
# define SPACESHIP_HPP

#include "AbstractObject.hpp"
#include "Weapon.hpp"
#include <iostream>

class SpaceShip : public AbstractObject
{
	public:
		SpaceShip();
		SpaceShip(std::string, unsigned int, int, int);
		SpaceShip(SpaceShip const & src);
		~SpaceShip();

		SpaceShip & operator=(SpaceShip const & rhs);
		
		void		setTitle(std::string const & title);
		void		setWeapon(Weapon * &weapon);
		std::string	getTitle() const;
		Weapon		*getWeapon() const;

	private:
		std::string	m_title;
		Weapon		*m_weapon;

};

std::ostream & operator<<(std::ostream & o, SpaceShip const & i);

#endif /* !SPACESHIP_HPP */
