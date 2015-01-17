#include <unistd.h>
#include "Display.hpp"
#include <iostream>
#include <string>
#include <ncurses.h>
#include "Display.hpp"

int main()
{
	Display *d = new Display();
	int ch;
	initscr();          /* Start curses mode        */
	raw();
	noecho();
	keypad(stdscr, TRUE);       /* I need that nifty F1     */
	noecho();
	curs_set(0);                // desactive le curseur
	nodelay(stdscr, TRUE);      //desactive l attente dune touche pour continuer
	init_pair(1, COLOR_CYAN, COLOR_BLACK);

	printw("Press F1 to exit");
	refresh();
	while((ch = getch()) != KEY_F(1))
	{   
		d->set_win(d->ft_init_win());
		box(d->get_win(), 0 , 0);
		wrefresh(d->get_win());
		d->destroy_win(d->get_win());
		usleep(10000);
	}

	endwin();           /* End curses mode        */
	return 0;
}

