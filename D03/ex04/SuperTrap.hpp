#ifndef SUPERTRAP_HPP
# define SUPERTRAP_HPP

#include "FragTrap.hpp"
#include "NinjaTrap.hpp"
#include <iostream>
#include <string>

class SuperTrap : public NinjaTrap, public FragTrap
{
	public:
		SuperTrap();
		SuperTrap(std::string name);
		SuperTrap(SuperTrap const & src);
		~SuperTrap();
};

/*std::ostream & operator<<(std::ostream & o, SuperTrap const & i);*/

#endif /* !SUPERTRAP_HPP */
