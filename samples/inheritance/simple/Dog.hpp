#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>

class Dog
{
	public:
		Dog();
		Dog(Dog const & src);
		~Dog();

		Dog & operator=(Dog const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Dog const & i);

#endif /* !DOG_HPP */
