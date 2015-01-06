#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie() : m_name(""), m_type("")
{
	std::cout << "A zombie is being created." << std::endl;
}

Zombie::~Zombie()
{
	if (m_type.compare("randomChump") == 0)
	{
		std::cout << "This Zombie was too random and destroyed itself in confusion." << std::endl;
	}
	else
	{
		std::cout << "Another Zombie left our army. R.I.P " << m_name << std::endl;
	}
}

void	Zombie::annouce()
{
	std::cout << "<" 
		<< m_name
		<< " ("
		<< m_type 
		<< ")> Braiiiiiiinnnssss..." 
		<< std::endl;
}

void	Zombie::setName(std::string name)
{
	m_name = name;
}

void	Zombie::setType(std::string type)
{
	m_type = type;
}

std::string	Zombie::getName()
{
	return (m_name);
}

std::string	Zombie::getType()
{
	return (m_type);
}
