#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public:
		Weapon();
		Weapon(Weapon const & src);
		~Weapon();

		Weapon & operator=(Weapon const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Weapon const & i);

#endif /* !WEAPON_HPP */
