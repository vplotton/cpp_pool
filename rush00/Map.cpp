#include "Map.hpp"

Map::Map()
{
}

Map::Map(Map const & src)
{
	*this = src;
}

Map::~Map()
{
}

Map & Map::operator=(Map const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Map const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
