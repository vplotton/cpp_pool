#ifndef MOVEMENT_HPP
# define MOVEMENT_HPP

#include <iostream>

class Movement
{
	public:
		Movement();
		Movement(Movement const & src);
		~Movement();

		Movement & operator=(Movement const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Movement const & i);

#endif /* !MOVEMENT_HPP */
