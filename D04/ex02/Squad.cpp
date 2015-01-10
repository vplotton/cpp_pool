#include "Squad.hpp"

Squad::Squad() : m_count(0), m_squad(new ISpaceMarine*[100])
{
}

Squad::Squad(Squad const & src) : m_count(0), m_squad(new ISpaceMarine*[100])
{
	*this = src;
}

Squad::~Squad()
{
	for (int i = 0; i < getCount() ; ++i)
	{
		delete m_squad[i];
	}
	delete [] m_squad;
}

Squad & Squad::operator=(Squad const & rhs)
{
	if (this != &rhs)
	{
		m_count = rhs.m_count;
		for (int i = 0; i < getCount() ; ++i)
		{
			m_squad[i] = rhs.m_squad[i]->clone();
		}
	}
	return (*this);
}

int		Squad::getCount() const
{
	return m_count;
}

ISpaceMarine	*Squad::getUnit(int unit)
{
	ISpaceMarine *marine = NULL;

	if (unit < getCount() && unit > -1)
	{
		marine = m_squad[unit];
	}
	else
	{
		std::cout << "Index not found." << std::endl;
	}
	return (marine);
}

int		Squad::push(ISpaceMarine * spaceMarine)
{
	if (spaceMarine == NULL)
	{
		return getCount();
	}

	for (int i = 0 ; i < getCount() ; ++i)
	{
		if (spaceMarine == m_squad[i])
		{
			return getCount();
		}
	}

	m_squad[getCount()] = spaceMarine;
	m_count++;

	return getCount();
}

/*
std::ostream & operator<<(std::ostream & o, Squad const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
*/
