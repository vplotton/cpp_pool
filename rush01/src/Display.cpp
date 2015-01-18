/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <cycharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 19:03:10 by cycharbo          #+#    #+#             */
/*   Updated: 2015/01/18 20:40:17 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Display.hpp"
#include <ncurses.h>
#include <list>
#include <map>
#include <vector>
#include <unistd.h>
#include "AbstractModule.hpp"
#include "Info.hpp"


int Display::cpt = 0;
int Display::begin = 0;

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

void	Display::printGraph(WINDOW *win)
{
	std::list<int>::iterator b = list.begin();
	std::list<int>::iterator end = list.end();
	std::list<int>::iterator it ;
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	wattron(win, COLOR_PAIR(1));

	int x = 0;
	//	int y = 0;
	for(it = b; it != end; ++it)
	{
		//	for(int i = 0; i < *it; i++)
		//	{
		//		mvwaddch(win, i, x, ACS_VLINE);
		//	}
		mvwvline(win,  0,  x, '*',  *it);
		x++;
	}
	//	mvwaddch(win, y, x, ACS_DIAMOND);
	wattroff(win, COLOR_PAIR(1));
	wrefresh(win);


}


void	Display::fill_pos(void)
{
	int ch = 0;
	printw( "Entrez le numero du module.");
	printw("\n");
	printw( "F2 pour valider les choix" );
	printw("\n 1 - CPU\n");
	printw("\n 2 - MEMORY\n");
	printw("\n 3 - SWAP MEMORY\n");
	printw("\n 4 - NETWORK\n");
	printw("\n 5 - OS INFO\n");
	printw("\n 6 - CLOCK\n");
	printw("\n 7 - USER\n");
	for(int i = 0; i < 10 ; i++)
	{
		check[i] = true;
	}
	while((ch = getch()) != KEY_F(2))
	{
		if (ch == 49)
		{
			if (check[0] == true)
			{
				this->_pos.insert(std::make_pair(0, 30));
				cpt = cpt + 1;
				printw("module 1 ajoute\n");
				check[0] = false;
			}
			else
				printw("\nmodule deja ajoute\n");
		}else if (ch == 50)
		{
			if (check[1] == true)
			{
				this->_pos.insert(std::make_pair(1,30));
				cpt = cpt + 1;
				printw("module 2 ajoute\n");
				check[1] = false;
			}
			else
			{
				printw("\nmodule deja ajoute\n");
			}
		}
		else if (ch == 51)
		{
			if (check[2] == true)
			{
				this->_pos.insert(std::make_pair(2,30));
				cpt = cpt + 1;
				printw("module 3 ajoute\n");
				check[2] = false;
			}
			else
			{
				printw("\nmodule deja ajoute\n");
			}
		}
		else if (ch == 52)
		{
			if (check[3] == true)
			{
				this->_pos.insert(std::make_pair(3,30));
				cpt = cpt + 1;
				printw("module 4 ajoute\n");
				check[3] = false;
			}
			else
			{
				printw("\nmodule deja ajoute\n");
			}
		}
		else if (ch == 53)
		{
			if (check[4] == true)
			{
				this->_pos.insert(std::make_pair(4,30));
				cpt = cpt + 1;
				printw("module 5 ajoute\n");
				check[4] = false;
			}
			else
			{
				printw("\nmodule deja ajoute\n");
			}
		}
		else if (ch == 54)
		{
			if (check[5] == true)
			{
				this->_pos.insert(std::make_pair(5,30));
				cpt = cpt + 1;
				printw("module 6 ajoute\n");
				check[5] = false;
			}
			else
			{
				printw("\nmodule deja ajoute\n");
			}
		}
		else if (ch == 55)
		{
			if (check[6] == true)
			{
				this->_pos.insert(std::make_pair(6,30));
				cpt = cpt + 1;
				printw("module 7 ajoute\n");
				check[6] = false;
			}
			else
			{
				printw("\nmodule deja ajoute\n");
			}
		}

	}
	erase();
	printw(" Selection effectue, merci ");
	sleep(1);
}

void	Display::makeBox()
{
	int i = 0;

	std::map<int, int>::iterator t = _pos.begin();
	for (std::map<int,int >::iterator it = _pos.begin() ; it != _pos.end() ; ++it)
	{
		tab[it->first] = new Box(it->first, it->second);
		i++;

	}
}

void	Display::printBox(void)
{
	for(int i = 0; i < 10; i++)
	{
		if (check[i] == false)
		{
			std::map<std::string, std::string> map = tab[i]->getMapInfo();
			for(std::map<std::string,std::string>::iterator it = map.begin(); it != map.end(); ++it)
			{
				(void)it;
			}
			wrefresh(tab[i]->getWinBox());
		}
	}
}

	void	Display::fillBox(AbstractModule::Type type, std::vector<Info>::iterator it ,int i, std::string titre)
{
	if (check[type] == false )
	{
		if ( begin == 0)
		{
			mvwprintw(tab[type]->getWinBox(), tab[type]->getY() + i,   3,  titre.c_str());
		}
		mvwprintw(tab[type]->getWinBox(), tab[type]->getY() + 3 + i,  3 , it->getName().c_str());
		mvwprintw(tab[type]->getWinBox(), tab[type]->getY()+ 3 +  i, it->getName().size() + 5, it->convert().c_str());
				i++;
	   }
}

Box *& Display::getWindows(int i)
{
	return (tab[i]);
}

bool Display::getCheck(int nb)
{
	return (check[nb]);
}
