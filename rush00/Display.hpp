#ifndef DISPLAY_HPP
# define DISPLAY_HPP

#include <iostream>

class Display
{
	public:
		Display();
		Display(Display const & src);
		~Display();

		Display & operator=(Display const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Display const & i);

#endif /* !DISPLAY_HPP */
