#include "Display.hpp"
#include <ncurses.h>

Display::Display()
{
}

Display::Display(Display const & src)
{
	*this = src;
}

Display::~Display()
{
}

Display & Display::operator=(Display const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}


WINDOW * Display::get_win()
{
	return (_win);
}

void Display::set_win(WINDOW* win)
{
	this->_win = win;
}

WINDOW*	Display::ft_init_win()
{
	WINDOW *win;
	int height = 50;
	int width = 100;
	int starty = 0;
	int startx = 0;

	win = newwin(height, width, starty, startx);
	box(win, 0 , 0);
	wrefresh(win);
	return (win);
}

void Display::destroy_win(WINDOW *win)
{
	wborder(win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(win);
	delwin(win);
}

void	Display::print_obj(WINDOW *win, int x, int y, int type)
{
	if (type == 0)
	{
		mvwaddch(win, y, x, ACS_DIAMOND);
		//wrefresh(_win);
	}
	else if (type == 1)
	{
		mvwaddch(win, y, x, ACS_DARROW);
		wrefresh(_win);
	}
	else if (type == 2)
	{
		mvwaddch(win, y, x, ACS_BTEE);
		wrefresh(_win);
	}
	
}
