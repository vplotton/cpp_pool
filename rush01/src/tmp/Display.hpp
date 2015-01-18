#ifndef DISPLAY_HPP
# define DISPLAY_HPP

#include <iostream>
#include <ncurses.h>
#include <list>
#include <string>
#include <map>
#include <vector>
#include "Box.hpp"
//#include "Info.hpp"

class Display
{
	public:
					Display();
					Display(Display const & src);
					~Display();
		WINDOW *	get_win(void);
		Display & 	operator=(Display const & rhs);
		void 		set_win(WINDOW *win);
		void		destroy_win(WINDOW * win);
		WINDOW*  	ft_init_win(void);
		void		printGraph(WINDOW *win);
		void		fill_pos();
		void		makeBox();
		void		printBox();
		static int	cpt;
//		void    fillBox(std::vector<Info> infos, unsigned int index);
		void    fillBox(unsigned int index);
			std::list<int>  list;
	private:
					WINDOW* _win;
					std::map<int,int > _pos;
					Box		*tab[10];
};


#endif /* !DISPLAY_HPP */
