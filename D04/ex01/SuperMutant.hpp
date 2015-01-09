#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"
#include <iostream>

class SuperMutant : public Enemy
{
	public:
		SuperMutant();
		SuperMutant(SuperMutant const & src);
		~SuperMutant();

		SuperMutant & operator=(SuperMutant const & rhs);

		virtual void    takeDamage(int);

	private:

};

/*
std::ostream & operator<<(std::ostream & o, SuperMutant const & i);
*/

#endif /* !SUPERMUTANT_HPP */
