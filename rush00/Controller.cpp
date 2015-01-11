#include "Controller.hpp"

Controller::Controller()
{
}

Controller::Controller(Controller const & src)
{
	*this = src;
}

Controller::~Controller()
{
}

Controller & Controller::operator=(Controller const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

void Controller::ft_get_input(int key, Display  *& d, int &x, int &y)
{
	switch(key)
	{	case KEY_LEFT:
			d->print_obj(d->get_win(),--x, y, 0);
			std::cerr << key << std::endl;
			wrefresh(d->get_win());
			break;
		case KEY_RIGHT:
			d->print_obj(d->get_win(), x++, y, 0);
			wrefresh(d->get_win());
			break;
		case KEY_UP:
			d->print_obj(d->get_win(), x, --y, 0);
			wrefresh(d->get_win());
			break;
		case KEY_DOWN:
			d->print_obj(d->get_win(),x, ++y, 0);
			wrefresh(d->get_win());
			break;	
	}
}
