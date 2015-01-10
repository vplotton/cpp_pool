#include "Enemy.hpp"

Enemy::Enemy()
{
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::~Enemy()
{
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Enemy const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
