#include "Enemy.hpp"

Enemy::Enemy() :
	AbstractObject(AbstractObject::ENEMY, 1, 0, 0)
{
}

Enemy::Enemy(unsigned int life, int x, int y) :
	AbstractObject(AbstractObject::ENEMY, life, x, y)
{
}

Enemy::Enemy(Enemy const & src) :
	AbstractObject(AbstractObject::ENEMY, 1, 0, 0)
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
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Enemy const & i)
{
	o << "Object - [ type : " << i.getType()
		<< " ] - [ name : " << i.getName()
		<< " ] [ life : " << i.getLife()
		<< " ]" << std::endl;
	return (o);
}
