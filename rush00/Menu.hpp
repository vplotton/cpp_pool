#ifndef MENU_HPP
# define MENU_HPP

#include <iostream>

class Menu
{
	public:
		Menu();
		Menu(Menu const & src);
		~Menu();

		Menu & operator=(Menu const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Menu const & i);

#endif /* !MENU_HPP */
