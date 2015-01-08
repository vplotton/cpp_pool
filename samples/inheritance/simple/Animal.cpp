#include "Animal.hpp"

Animal::Animal()
{
}

Animal::Animal(Animal const & src)
{
	*this = src;
}

Animal::~Animal()
{
}

Animal & Animal::operator=(Animal const & rhs)
{
	if (this != &rhs)
	{
		m_ourVar = rhs.m_ourVar;
		m_myVar = rhs.m_myVar;
	}
	return (*this);
}

void	Animal::setMyVar(int const var)
{
	m_myVar = var;
}

void    Animal::setOurVar(int const var)
{
	        m_ourVar = var;
}

int	Animal::getMyVar()
{
	return (m_myVar);
}

int     Animal::getOurVar()
{
	        return (m_ourVar);
}


std::ostream & operator<<(std::ostream & o, Animal const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
