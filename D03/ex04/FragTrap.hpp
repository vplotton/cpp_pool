#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public virtual ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const & src);
		~FragTrap();

		FragTrap & operator=(FragTrap const & rhs);

		void	vaulthunter_dot_exe(std::string const & target) const;

};

/*std::ostream & operator<<(std::ostream & o, FragTrap const & i);*/

#endif /* !FRAGTRAP_HPP */
