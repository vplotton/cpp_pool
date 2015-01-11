#ifndef MENU_HPP
# define MENU_HPP

#include <iostream>
#include <ncurses.h>
#include "Display.hpp"
#include "SpaceShip.hpp"

class Menu
{
	public:
		Menu();
		Menu(Menu const & src);
		~Menu();

		Menu & 	operator=(Menu const & rhs);
		WINDOW 	*get_menu();
		void 	set_menu(WINDOW* menu);
		void	print_life(SpaceShip *ship);
		void	print_score();
		WINDOW*	init_menu();
		void	destroy_menu(WINDOW *menu);
	private:
			int _score;
			WINDOW *_menu;
};
#endif /* !MENU_HPP */
