#include "Brain.hpp"
#include <sstream>

Brain::Brain()
{
}

Brain::~Brain()
{
}

std::string	Brain::identify() const
{
	void const *address = static_cast<const void*>(this);
	std::ostringstream stringStream;
	std::string output("");
	
	stringStream << address;
	output += stringStream.str();

	return (output);
}
