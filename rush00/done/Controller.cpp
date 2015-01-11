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

AbstractObject *Controller::ft_get_input(int key, Display  *& d, SpaceShip *&ship)
{
	AbstractObject *newProjectile = NULL;
	switch(key)
	{	case KEY_LEFT:
			ship->getMovement()->goLeft();
			d->print_obj(d->get_win(), ship->getMovement()->getX(), ship->getMovement()->getY(), 0);
			
			wrefresh(d->get_win());
			break;
		case KEY_RIGHT:
			            ship->getMovement()->goRight();
						            d->print_obj(d->get_win(), ship->getMovement()->getX(), ship->getMovement()->getY(), 0);
			wrefresh(d->get_win());
			break;
		case KEY_UP:
			            ship->getMovement()->goUp();
						            d->print_obj(d->get_win(), ship->getMovement()->getX(), ship->getMovement()->getY(), 0);
			wrefresh(d->get_win());
			break;
		case KEY_DOWN:
			            ship->getMovement()->goDown();
						            d->print_obj(d->get_win(), ship->getMovement()->getX(), ship->getMovement()->getY(), 0);
			wrefresh(d->get_win());
			break;	
		case KEY_BACKSPACE:
		case KEY_ENTER:
		case KEY_DC:
			newProjectile = ship->getWeapon()->shoot(ship->getMovement());
			break ;
	}
	return newProjectile;
}
