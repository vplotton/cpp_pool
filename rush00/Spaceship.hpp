#ifndef SPACESHIP_HPP
# define SPACESHIP_HPP

#include "AbstractObject.hpp"
#include <iostream>

class Spaceship : public AbstractObject
{
	public:
		Spaceship();
		Spaceship(std::string name);
		Spaceship(Spaceship const & src);
		~Spaceship();

		Spaceship & operator=(Spaceship const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Spaceship const & i);

#endif /* !SPACESHIP_HPP */
