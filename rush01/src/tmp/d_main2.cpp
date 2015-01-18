/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_main2.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cycharbo <cycharbo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/18 02:02:46 by cycharbo          #+#    #+#             */
/*   Updated: 2015/01/18 05:38:29 by cycharbo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <iostream>
#include <string>
#include <ncurses.h>
#include "Display.hpp"
#include <list>
//#include "Info.hpp"
#include "Box.hpp"

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

	//d->set_win(d->ft_init_win());
	d->fill_pos();	
	d->makeBox();
	erase();
	d->fillBox(0);
	while((ch = getch()) != KEY_F(1))
	{
		d->printBox();
		//		d->destroy_win(d->get_win());
		//		d->set_win(d->ft_init_win());
		//		box(d->get_win(), 0 , 0);
		//		d->printGraph(d->get_win());
		//		wrefresh(d->get_win());
		usleep(100000);
	}
	endwin();           /* End curses mode        */
	return 0;
}

