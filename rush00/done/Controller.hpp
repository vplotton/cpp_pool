#ifndef CONTROLLER_HPP
# define CONTROLLER_HPP

#include <iostream>
#include "Display.hpp"
#include "SpaceShip.hpp"

class Controller
{
	public:
		Controller();
		Controller(Controller const & src);
		~Controller();
		Controller & operator=(Controller const & rhs);
		void ft_get_input(int key, Display  *& d, SpaceShip *& ship);
	private:

};

std::ostream & operator<<(std::ostream & o, Controller const & i);

#endif /* !CONTROLLER_HPP */
