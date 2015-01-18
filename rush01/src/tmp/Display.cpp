#include "Display.hpp"
#include <ncurses.h>
#include <list>
#include <map>
#include <vector>
#include <unistd.h>
#include "Info.hpp"

int Display::cpt = 0;
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
	printw("\n 1 - User\n");
	printw("\n 2 - Clock\n");
	bool	check[10]= {true,true};

	while((ch = getch()) != KEY_F(2))
	{
		if (ch == 49)
		{
			if (check[0] == true)
			{
				this->_pos.insert(std::make_pair(1, 20));
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
				this->_pos.insert(std::make_pair(2,20));
				cpt = cpt + 1;
				printw("module 2 ajoute\n");
				check[1] = false;
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
		// std::cerr << t->first << " raaaa " << std::endl;
		//   std::cerr << t->second << " raaaa " << std::endl;
		// std::cerr << i << " raaaa " << std::endl;
		// sleep(1);
		if ( i < 10)
		{
			tab[i] = new Box(it->first, it->second);
			i++;
			//std::cerr << it->first << " TTTTTT  " << it->second << std::endl;
		}
		else
			break;
	}
}

void	Display::printBox(void)
{
	int x = 0;
	int y = 1;
	for(int i = 0; i < cpt; i++)
	{
		std::map<std::string, std::string> map = tab[i]->getMapInfo();
		for(std::map<std::string,std::string>::iterator it = map.begin(); it != map.end(); ++it)
		{
			mvwprintw(tab[i]->_box, y, 
		}
		wrefresh(tab[i]->getWinBox());
	}
}

void	Display::fillBox(unsigned int index)
{

	tab[index]->setText("titre", "texte");
	tab[index]->setText("titre", "texte");		
	tab[index]->setText("titre", "texte");

	/*
	for(std::vector<Info>::iterator it = infos.begin() ; infos.end() ; ++it)
	{
		tab[index]->setText(it->getName(), it->convert(it->getInfo())); 
	}*/
} 
