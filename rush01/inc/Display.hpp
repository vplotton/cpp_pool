#ifndef DISPLAY_HPP
# define DISPLAY_HPP

#include <iostream>
#include <ncurses.h>
#include <list>
#include <string>
#include <map>
#include <vector>
#include "Box.hpp"
#include "AbstractModule.hpp"
#include "Info.hpp"

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
		static int  begin;;
		void    fillBox(AbstractModule::Type type, std::vector<Info>::iterator it , int i, std::string titre);
			std::list<int>  list;
			Box *& getWindows(int i);
			bool	getCheck(int nb);
	private:
					
					WINDOW* _win;
					std::map<int,int > _pos;
					Box		*tab[10];
					bool	check[10];
};


#endif /* !DISPLAY_HPP */
