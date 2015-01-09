#include "Squad.hpp"

Squad::Squad()
{
}

Squad::Squad(Squad const & src)
{
	*this = src;
}

Squad::~Squad()
{
}

Squad & Squad::operator=(Squad const & rhs)
{
	if (this != &rhs)
	{

		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

int		Squad::getCount() const
{
	return m_count;
}

ISpaceMarine	*Squad::getUnit(int unit) const
{
	return (m_squad[i]);
}

int		Squad::push(ISpaceMarine * spaceMarine) const
{
}

std::ostream & operator<<(std::ostream & o, Squad const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
