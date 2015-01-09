#include "Victim.hpp"

Victim::Victim() : m_name("")
{
}

Victim::Victim(std::string name) : m_name(name)
{
	std::cout << "Some random victim called " << m_name << " just popped !" << std::endl;
}

Victim::Victim(Victim const & src)
{
	*this = src;
}

Victim::~Victim()
{
	std::cout << "Victim " << m_name << " just died for no apparent reason !" << std::endl;
}

Victim & Victim::operator=(Victim const & rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
	}
	return (*this);
}

void	Victim::setName(std::string const name)
{
	m_name = name;
}

std::string	Victim::getName() const
{
	return m_name;
}

void	Victim::getPolymorphed() const
{
	std::cout << m_name << " has been turned into a cute little sheep !" << std::endl;
}

void	Victim::introduceHimself() const
{
	std::cout << "I'm " << m_name << ", and I like otters !" << std::endl;
}


std::ostream & operator<<(std::ostream & o, Victim const & i)
{
	o << "I'm " << i.getName() << ", and I like otters !" << std::endl;
	return (o);
}
