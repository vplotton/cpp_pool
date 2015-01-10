#ifndef SPACESHIP_HPP
# define SPACESHIP_HPP

#include <iostream>

class Spaceship
{
	public:
		Spaceship();
		Spaceship(Spaceship const & src);
		~Spaceship();

		Spaceship & operator=(Spaceship const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Spaceship const & i);

#endif /* !SPACESHIP_HPP */
