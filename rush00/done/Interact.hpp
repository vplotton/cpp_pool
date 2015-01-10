#ifndef INTERACT_HPP
# define INTERACT_HPP

#include <iostream>

class Interact
{
	public:
		Interact();
		Interact(Interact const & src);
		~Interact();

		Interact & operator=(Interact const & rhs);


	private:
};

/*std::ostream & operator<<(std::ostream & o, Interact const & i);*/

#endif /* !INTERACT_HPP */
