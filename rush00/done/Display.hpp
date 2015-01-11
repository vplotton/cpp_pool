#ifndef DISPLAY_HPP
# define DISPLAY_HPP

#include <iostream>
#include <ncurses.h>

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
		void		print_obj(WINDOW *win,int x, int y, int type);

	private:
					WINDOW* _win;

};


#endif /* !DISPLAY_HPP */
