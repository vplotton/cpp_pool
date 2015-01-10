#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include "AbstractObject.hpp"
#include <iostream>

class Projectile : public AbstractObject
{
	public:
		Projectile();
		Projectile(int, int);
		Projectile(Projectile const & src);
		~Projectile();

		Projectile & operator=(Projectile const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Projectile const & i);

#endif /* !PROJECTILE_HPP */
