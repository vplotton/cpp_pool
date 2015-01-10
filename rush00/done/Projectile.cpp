#include "Projectile.hpp"

Projectile::Projectile() :
	AbstractObject(PROJECTILE, 1, 0, 0)
{
}

Projectile::Projectile(int x, int y) :
	AbstractObject(PROJECTILE, 1, x, y)
{
}

Projectile::Projectile(Projectile const & src) :
	AbstractObject(PROJECTILE, 1, 0, 0)
{
	*this = src;
}

Projectile::~Projectile()
{
}

Projectile & Projectile::operator=(Projectile const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Projectile const & i)
{
	o << "Object - [ type : " << i.getType()
		<< " ] - [ name : " << i.getName()
		<< " ] [ life : " << i.getLife()
		<< " ]" << std::endl;
	return (o);
}
