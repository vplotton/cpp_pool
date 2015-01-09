#include "AssaultTerminator.hpp"

AssaultTerminator::AssaultTerminator()
{
	std::cout << "* teleports from space *" << std::endl;
}

AssaultTerminator::AssaultTerminator(AssaultTerminator const & src)
{
	*this = src;
}

AssaultTerminator::~AssaultTerminator()
{
	std::cout << "I’ll be back ..." << std::endl;
}

AssaultTerminator & AssaultTerminator::operator=(AssaultTerminator const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

void    AssaultTerminator::battleCry() const
{
	    std::cout << "This code is unclean. PURIFY IT !" << std::endl;
}

void    AssaultTerminator::rangedAttack() const
{
	    std::cout << "* does nothing *" << std::endl;
}

void    AssaultTerminator::meleeAttack() const
{
	    std::cout << "* attacks with chainfists *" << std::endl;
}

std::ostream & operator<<(std::ostream & o, AssaultTerminator const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
