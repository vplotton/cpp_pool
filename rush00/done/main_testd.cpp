#include "Display.hpp"
#include "Controller.hpp"
#include "SpaceShip.hpp"
#include "AbstractObject.hpp"
#include "Movement.hpp"
#include <string>
#include <ncurses.h>
#include <unistd.h>
#include "Menu.hpp"

int main()
{
	Display *d = new Display();
	Controller *ctrl = new Controller();
	SpaceShip	*ship = new SpaceShip("gna", 1, 10, 10); 
	int		ch;
	Menu	*menu = new Menu();
	initscr();			/* Start curses mode 		*/
	d->set_win(d->ft_init_win());
	menu->set_menu(menu->init_menu());
	start_color();			/* Start the color functionality */
	raw(); 					// pour les ctrl truc
	keypad(stdscr, TRUE);		/* I need that nifty F1 	*/
	noecho();
	curs_set(0);				// desactive le curseur
	nodelay(stdscr, TRUE);		//desactive l attente dune touche pour continuer
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	refresh();
	printw("appuyer sur  une touche pour commencer");
	while((ch = getch()) != KEY_F(1))
	{
	//	menu->destroy_menu(menu->get_menu());
		d->destroy_win(d->get_win());
		d->set_win(d->ft_init_win());
		box(d->get_win(), 0 , 0);
		box(menu->get_menu(), 0 , 0);
		ctrl->ft_get_input(ch, d, ship);
		d->print_obj(d->get_win(), ship->getMovement()->getX(), ship->getMovement()->getY(), 0);
		menu->print_life(ship);
		wrefresh(d->get_win());
		wrefresh(menu->get_menu());
		usleep(100000);
	}
	endwin();
	delete d;
	delete ctrl;
	delete	menu;
}
