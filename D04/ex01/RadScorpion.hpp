#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"
#include <iostream>

class RadScorpion : public Enemy
{
	public:
		RadScorpion();
		RadScorpion(RadScorpion const & src);
		~RadScorpion();

		RadScorpion & operator=(RadScorpion const & rhs);

		virtual void    takeDamage(int);

	private:

};

/*
std::ostream & operator<<(std::ostream & o, RadScorpion const & i);
*/

#endif /* !RADSCORPION_HPP */
