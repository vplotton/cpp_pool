#include "Enemy.hpp"
#include "EnemyMovement.hpp"

Enemy::Enemy() :
	AbstractObject(AbstractObject::ENEMY, 1)
{
	IMovement::e_dir	*pattern = NULL;
	unsigned int		patternSize = 0;
	m_movement = new EnemyMovement(20, 20, 1, patternSize, pattern);
	m_movement->setDirection(IMovement::LEFT);
}

Enemy::Enemy(unsigned int life, int x, int y) :
	AbstractObject(AbstractObject::ENEMY, life)
{
	IMovement::e_dir	*pattern = NULL;
	unsigned int		patternSize = 0;
	m_movement = new EnemyMovement(x, y, 1, patternSize, pattern);
	m_movement->setDirection(IMovement::LEFT);
}

Enemy::Enemy(Enemy const & src) :
	AbstractObject(src)
{
	IMovement::e_dir	*pattern = NULL;
	unsigned int		patternSize = 0;
	m_movement = new EnemyMovement(20, 20, 1, patternSize, pattern);
	*this = src;
}

Enemy::~Enemy()
{
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs)
	{
		m_movement = new EnemyMovement(*(EnemyMovement*)rhs.m_movement);
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Enemy const & i)
{
	o << "Object:" << std::endl
		<< "    - type : " << i.getType() << std::endl
		<< "    - name : " << i.getName() << std::endl
		<< "    - life : " << i.getLife() << std::endl
		<< "    - " << *(EnemyMovement*)i.getMovement() << std::endl;
	return (o);
}
