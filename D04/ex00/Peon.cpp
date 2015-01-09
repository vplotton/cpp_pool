#include "Peon.hpp"

Peon::Peon() : Victim()
{
}

Peon::Peon(std::string name) : Victim(name)
{
	std::cout << "Zog zog." << std::endl;
}

Peon::Peon(Peon const & src) : Victim(src)
{
	*this = src;
}

Peon::~Peon()
{
	std::cout << "Bleuark..." << std::endl;
}

Peon & Peon::operator=(Peon const & rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
	}
	return (*this);
}

void	Peon::getPolymorphed() const
{
	std:: cout << m_name <<  " has been turned into a pink pony !" << std::endl;
}
/*
std::ostream & operator<<(std::ostream & o, Victim const & i)
{
	o << "I'm " << i.getName() << ", and I like otters !";
	return (o);
}
*/
