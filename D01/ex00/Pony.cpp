#include "Pony.hpp"
#include <iostream>

Pony::Pony()
{
	std::cout << "A Pony just flew from the sky" << std::endl;
}

Pony::~Pony()
{
	std::cout << "The pony you're looking for does no longer exists..." << std::endl;
	std::cout << m_name << " is dead" << std::endl;
	std::cout << std::endl;
}

void	Pony::setName(std::string name)
{
	std::cout << "Hey, my name is " << name << ". Nice to meet you." << std::endl;
	std::cout << std::endl;
	m_name = name;
}

std::string Pony::getName()
{
	return (m_name);
}
