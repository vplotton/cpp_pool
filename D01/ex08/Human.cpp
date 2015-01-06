#include "Human.hpp"
#include <iostream>

void	Human::meleeAttack(std::string const & target)
{
	std::cout << "Melee attack on " << target << std::endl;
}

void	Human::rangedAttack(std::string const & target)
{
	std::cout << "Ranged attack on " << target << std::endl;
}

void	Human::intimidatingShout(std::string const & target)
{
	std::cout << "intimidating shout on " << target << std::endl;
}

void	Human::action(std::string const & action_name, std::string const & target)
{
	t_atkFunc atkFunctions[3] =
	{
		{ "meleeAttack", &Human::meleeAttack },
		{ "rangedAttack", &Human::rangedAttack },
		{ "intimidatingShout", &Human::intimidatingShout}
	};

	for (int i = 0; i < 3 ; ++i)
	{
		if (atkFunctions[i].name.compare(action_name) == 0)
		{
			(this->*(atkFunctions[i].func))(target);
		}
	}
}
