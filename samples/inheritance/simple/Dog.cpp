#include "Dog.hpp"

Dog::Dog()
{
}

Dog::Dog(Dog const & src)
{
	*this = src;
}

Dog::~Dog()
{
}

Dog & Dog::operator=(Dog const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Dog const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
