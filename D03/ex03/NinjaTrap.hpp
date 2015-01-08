#ifndef NINJATRAP_HPP
# define NINJATRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class NinjaTrap : public ClapTrap
{
	public:
		NinjaTrap();
		NinjaTrap(std::string name);
		NinjaTrap(NinjaTrap const & src);
		~NinjaTrap();

		NinjaTrap & operator=(NinjaTrap const & rhs);

		void	healNoob(std::string const & target);
		
		void	ninjaShoebox(FragTrap const trap, std::string const target);
		void	ninjaShoebox(ScavTrap const trap, std::string const target);
		void	ninjaShoebox(NinjaTrap const trap, std::string const target);

};

/*std::ostream & operator<<(std::ostream & o, NinjaTrap const & i);*/

#endif /* !NINJATRAP_HPP */
