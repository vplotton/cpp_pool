#ifndef INTERFACEDISPLAY_HPP
# define INTERFACEDISPLAY_HPP

#include <ncurses.h>
#include <string>
#include <vector>
#include "AbstractModule.hpp"
#include "Info.hpp"

class InterfaceDisplay
{
	public:
		virtual ~InterfaceDisplay() {}

		virtual void		destroy_win(WINDOW * win) = 0;
		virtual void		printGraph(WINDOW *win) = 0;
		virtual void		fill_pos() = 0;
		virtual void		makeBox() = 0;
		virtual void		printBox() = 0;
		virtual void    fillBox(AbstractModule::Type type,
				std::vector<Info>::iterator it , int i, std::string titre) = 0;
};


#endif /* !INTERFACEDISPLAY_HPP */
