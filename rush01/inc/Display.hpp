#ifndef DISPLAY_HPP
# define DISPLAY_HPP

#include "InterfaceDisplay.hpp"
#include <list>
#include <map>
#include "Box.hpp"

class Display : public InterfaceDisplay
{
	public:
					Display();
					Display(Display const & src);
					virtual ~Display();
		WINDOW *	get_win(void);
		Display & 	operator=(Display const & rhs);
		void 		set_win(WINDOW *win);
		virtual void		destroy_win(WINDOW * win);
		WINDOW*  	ft_init_win(void);
		virtual void		printGraph(WINDOW *win);
		virtual void		fill_pos();
		virtual void		makeBox();
		virtual void		printBox();
		static int	cpt;
		static int  begin;;
		virtual void    fillBox(AbstractModule::Type type,
				std::vector<Info>::iterator it , int i, std::string titre);
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
