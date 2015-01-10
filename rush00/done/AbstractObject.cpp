#include "AbstractObject.hpp"

AbstractObject::AbstractObject() : m_life(0),
	m_movement(new Movement),
	m_interact(new Interact)
{
}

AbstractObject::AbstractObject(AbstractObject const & src) : m_life(0),
	m_movement(new Movement),
	m_interact(new Interact)
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

	if (m_interact)
	{
		delete m_interact;
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
		m_interact = new Interact(*rhs.m_interact);
	}
	return (*this);
}

void	AbstractObject::setType(e_type const &type)
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

void    AbstractObject::setInteract(Interact * &interact)
{
	    m_interact = interact;
}

AbstractObject::e_type	AbstractObject::getType() const
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

Interact		*AbstractObject::getInteract() const
{
	return m_interact;
}

std::ostream & operator<<(std::ostream & o, AbstractObject const & i)
{
	o << "Object - [ type : " << i.getType()
		<< " ] - [ name : " << i.getName()
		<< " ] [ life : " << i.getLife()
		<< " ]" << std::endl;;
	return (o);
}
