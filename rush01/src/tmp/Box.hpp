#ifndef BOX_HPP
# define BOX_HPP

#include <iostream>
#include <map>
#include <ncurses.h>

class Box
{
	public:
		Box();
		Box(int type, int len);
		Box(Box const & src);
		~Box();

		Box & operator=(Box const & rhs);
		static int totalLen;
		static int startX;
		static int startY;
		WINDOW *getWinBox();
		void	setText(std::string title, std::string txt);
		std::map<std::string , std::string>  getMapInfo();
	private:
			WINDOW	*_box;
			int _len;
			int _h;
			int	_w;
			int _type;
			std::string _title;
			int posX;
			int posY;
			std::map<std::string , std::string>  _info;
};


#endif /* !BOX_HPP */
