#include "AbstractObject.hpp"

std::string const AbstractObject::typeNames[] =
{
	"Projectile",
	"SpaceShip",
	"Default",
	"Enemy"
};

AbstractObject::AbstractObject() : 
	m_type(AbstractObject::DEFAULT),
	m_name(typeNames[(int)AbstractObject::DEFAULT]),
	m_life(0),
	m_movement(new Movement)
{
}

AbstractObject::AbstractObject(e_object type, unsigned int life, int x, int y) :
	m_type(type),
	m_name(typeNames[((int)type < 4 ? (int)type : AbstractObject::DEFAULT)]),
	m_life(life),
	m_movement(new Movement(x, y, 1))
{
}

AbstractObject::AbstractObject(AbstractObject const & src) :
	m_type(AbstractObject::DEFAULT),
	m_name(typeNames[(int)AbstractObject::DEFAULT]),
	m_life(0),
	m_movement(new Movement)
{
	*this = src;
}

AbstractObject::~AbstractObject()
{
	m_life = 0;

	if (m_movement)
	{
		delete m_movement;
	}
}

AbstractObject & AbstractObject::operator=(AbstractObject const & rhs)
{
	if (this != &rhs)
	{
		m_type = rhs.m_type;
		m_name = rhs.m_name;
		m_life = rhs.m_life;
		m_movement = new Movement(*rhs.m_movement);
	}
	return (*this);
}

void	AbstractObject::setType(e_object const &type)
{
	m_type = type;
}

void    AbstractObject::setName(std::string const &name)
{
	m_name = name;
}

void    AbstractObject::setLife(unsigned int const &life)
{
	m_life = life;
}

void    AbstractObject::setMovement(Movement * &movement)
{
	m_movement = movement;
}

AbstractObject::e_object	AbstractObject::getType() const
{
	return m_type;
}

std::string		AbstractObject::getName() const
{
	return m_name;
}

unsigned int	AbstractObject::getLife() const
{
	return m_life;
}

Movement		*AbstractObject::getMovement() const
{
	return m_movement;
}

std::ostream & operator<<(std::ostream & o, AbstractObject const & i)
{
	o << "Object:" << std::endl
		<< "    - type : " << i.getType() << std::endl
		<< "    - name : " << i.getName() << std::endl
		<< "    - life : " << i.getLife() << std::endl
		<< "    - " << *i.getMovement() << std::endl;
	return (o);
}
