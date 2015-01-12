#ifndef ENEMY_HPP
# define ENEMY_HPP

#include "AbstractObject.hpp"
#include <iostream>

class Enemy : public AbstractObject
{
	public:
		Enemy();
		Enemy(unsigned int, int, int);
		Enemy(Enemy const & src);
		~Enemy();

		Enemy & operator=(Enemy const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Enemy const & i);

#endif /* !ENEMY_HPP */
