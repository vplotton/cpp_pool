#include "Human.hpp"

Human::Human() : m_brain(Brain())
{
}

Human::~Human()
{
}

std::string	Human::identify() const
{
	return (m_brain.identify());
}

Brain	Human::getBrain()
{
	return (m_brain);
}
