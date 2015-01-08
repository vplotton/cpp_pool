#include "Cat.hpp"

Cat::Cat()
{
}

Cat::Cat(Cat const & src)
{
	*this = src;
}

Cat::~Cat()
{
}

Cat & Cat::operator=(Cat const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Cat const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
