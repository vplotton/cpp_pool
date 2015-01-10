#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>

class Enemy
{
	public:
		Enemy();
		Enemy(Enemy const & src);
		~Enemy();

		Enemy & operator=(Enemy const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Enemy const & i);

#endif /* !ENEMY_HPP */
