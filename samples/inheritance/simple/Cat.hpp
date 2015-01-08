#ifndef CAT_HPP
# define CAT_HPP

#include <iostream>

class Cat
{
	public:
		Cat();
		Cat(Cat const & src);
		~Cat();

		Cat & operator=(Cat const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Cat const & i);

#endif /* !CAT_HPP */
