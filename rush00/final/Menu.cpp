#include "Menu.hpp"
#include <sstream>
#include <string>
Menu::Menu()
{
}

Menu::Menu(Menu const & src)
{
	*this = src;
}

Menu::~Menu()
{
}

Menu & Menu::operator=(Menu const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

WINDOW * Menu::get_menu()
{
	    return (_menu);
}

void Menu::set_menu(WINDOW* menu)
{
	    this->_menu = menu;
}

WINDOW*	Menu::init_menu(void)
{
	WINDOW *menu;
	int height = 5;
	int width = 100;
	int starty = 0;
	int startx = 0;

	menu = newwin(height, width, starty, startx);
	box(menu, 0 , 0);
	wrefresh(menu);
	return (menu);
}

void    Menu::print_life(SpaceShip *ship)
{
	int x = 3;
	int	y = 1;
	int i = 0;
	mvwprintw(_menu, y, x, "LIFE : ");
	x = 8;
	for( i = 0; i <(int) ship->getLife(); i++)
	{
		mvwaddch(_menu, y, x, ACS_DIAMOND);
			x++;
	}
	for (i = x; i < x + 10 ;i++)
	{
		mvwaddch(_menu, y, x, ' ');
	}
}

void    Menu::print_score(Game *g)
{
	int x = 50;
	int y = 1;
	//int i = 0;
	int number = (int)g->getScore();
	std::stringstream strs;
	strs << number;
	std::string temp_str = strs.str();
	char* char_type = (char*) temp_str.c_str();
	mvwprintw(_menu, y, x, "SCORE : ");
	x = 61;
//	for( i = 0; i < number; i++)
//	{
		mvwprintw(_menu, y, x, char_type);
		//std::cerr << char_type << std::endl;
//		x++;
//	}
//	for (i = x; i < x + 10 ;i++)
//	{
//		mvwaddch(_menu, y, x, ' ');
//	}
}

void Menu::destroy_menu(WINDOW *menu)
{
	wborder(menu, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(menu);
	delwin(menu);
}
