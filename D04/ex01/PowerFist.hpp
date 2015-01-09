#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"
#include <iostream>

class PowerFist : public AWeapon
{
	public:
		PowerFist();
		PowerFist(PowerFist const & src);
		~PowerFist();

		PowerFist & operator=(PowerFist const & rhs);

		virtual void	attack() const;

	private:

};

/*
std::ostream & operator<<(std::ostream & o, PowerFist const & i);
*/

#endif /* !POWERFIST_HPP */
