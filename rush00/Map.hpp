#ifndef MAP_HPP
# define MAP_HPP

#include <iostream>

class Map
{
	public:
		Map();
		Map(Map const & src);
		~Map();

		Map & operator=(Map const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Map const & i);

#endif /* !MAP_HPP */
