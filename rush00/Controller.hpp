#ifndef CONTROLLER_HPP
# define CONTROLLER_HPP

#include <iostream>

class Controller
{
	public:
		Controller();
		Controller(Controller const & src);
		~Controller();

		Controller & operator=(Controller const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Controller const & i);

#endif /* !CONTROLLER_HPP */
