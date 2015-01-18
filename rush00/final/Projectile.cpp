#include "Projectile.hpp"
#include "EnemyMovement.hpp"

Projectile::Projectile() :
	AbstractObject(PROJECTILE, 1)
{
	IMovement::e_dir    *pattern = NULL;
	unsigned int        patternSize = 0;
	m_movement = new EnemyMovement(20, 20, 1, patternSize, pattern);
	m_movement->setDirection(IMovement::LEFT);
}

Projectile::Projectile(int x, int y) :
	AbstractObject(PROJECTILE, 1)
{
	IMovement::e_dir    *pattern = NULL;
	unsigned int        patternSize = 0;
	m_movement = new EnemyMovement(x, y, 1, patternSize, pattern);
	m_movement->setDirection(IMovement::RIGHT);
}

Projectile::Projectile(Projectile const & src) :
	AbstractObject(src)
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
		m_movement = new EnemyMovement(*(EnemyMovement*)rhs.m_movement);
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
