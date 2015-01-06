#include "Brain.hpp"
#include <sstream>

Brain::Brain() : m_address(static_cast<const void*>(this))
{
}

Brain::~Brain()
{
}

std::string	Brain::identify() const
{
	std::ostringstream stringStream;
	std::string output("");
	
	stringStream << m_address;
	output += stringStream.str();

	return (output);
}
