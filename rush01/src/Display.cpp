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
	int starty = 5;
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
/*
void	Display::print_obj(WINDOW *win, int x, int y, int type)
{
	if (type == AbstractObject::SPACESHIP)
	{
		start_color();
		init_pair(1, COLOR_RED, COLOR_WHITE);
		wattron(win, COLOR_PAIR(1));
		mvwaddch(win, y, x, ACS_DIAMOND);
		wattroff(win, COLOR_PAIR(1));
		wrefresh(win);
	}else if (type ==AbstractObject::ENEMY)
	{
		start_color();
		init_pair(2, COLOR_RED, COLOR_BLACK);
		wattron(win, COLOR_PAIR(2));
		mvwaddch(win, y, x, ACS_LARROW);
		wattroff(win, COLOR_PAIR(2));
		wrefresh(win);
	}else if (type == AbstractObject::PROJECTILE)
	{
		start_color();
		init_pair(3, COLOR_GREEN, COLOR_BLACK);
		wattron(win, COLOR_PAIR(3));
		mvwaddch(win, y, x, ACS_HLINE);
		wattroff(win, COLOR_PAIR(3));
		wrefresh(win);
	}else if (type ==AbstractObject::BOSS)
	{
		start_color();
		init_pair(4, COLOR_GREEN, COLOR_BLACK);
		wattron(win, COLOR_PAIR(4));
		int j = 65;
		int i = 1;
		mvwprintw(win, i,j,"        .-'         '-.");i++;
		mvwprintw(win, i,j,"     .'                 '");i++;
		mvwprintw(win, i,j,"    '       '.   .'       '");i++;
		mvwprintw(win, i,j,"   / /       ' \\ /        \\ \\ ");i++;
		mvwprintw(win, i,j,"  '  |         :         |  '");i++;
		mvwprintw(win, i,j," /   |         .         |  ' \\");i++;
		mvwprintw(win, i,j," |   '\\         |         /   |");i++;
		mvwprintw(win, i,j," '. . '\\        |        / . .");i++;
		mvwprintw(win, i,j,"  |   '.\\      .'.      /.   |");i++;
		mvwprintw(win, i,j," ' \\  .  `-           -'  .  /");i++;
		mvwprintw(win, i,j,"   '.      .. ... ..      .");i++;
		mvwprintw(win, i,j,"    |  `` ` .     . ` ``  |");i++;
		mvwprintw(win, i,j,"    | .-_-.  '. .'  .-_-. |");i++;
		mvwprintw(win, i,j,"   .'( (O) )|  :  |( (O) )'");i++;
		mvwprintw(win, i,j,"    '\\.'---'/   :  ' \\---'./");i++;
		mvwprintw(win, i,j,"      \\_ .'  . ' .  '.\\ _/");i++;
		mvwprintw(win, i,j,"     .' /             \\ ");i++;
		mvwprintw(win, i,j,"     './ / /  / '\\ \\  \\ \\");i++;
		mvwprintw(win, i,j,"      : | | /|  : |  | :");i++;
		mvwprintw(win, i,j,"      | : | \\\\  | '  : ");i++;
		mvwprintw(win, i,j,"      | /'\\ \\/' '\\ | : /'\\ ");i++;
		mvwprintw(win, i,j,"      ' :/\\ \\ : ' ||  '\\ ");i++;
		mvwprintw(win, i,j,"      / | /\\ \\| : ' '\\  \\ \\");i++;
		mvwprintw(win, i,j,"     / / /  \\/ /| :  |  \\ \\");i++;
		mvwprintw(win, i,j,"    / / :   / /\\ \\ \\ /   \\ \\");i++;


		wattroff(win, COLOR_PAIR(4));
		wrefresh(win);
	}

}*/
