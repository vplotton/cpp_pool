#include "Human.hpp"

Human::Human()
{
}

Human::~Human()
{
}

std::string	Human::identify() const
{
	return (m_brain.identify());
}

Brain const &Human::getBrain()
{
	return (m_brain);
}
