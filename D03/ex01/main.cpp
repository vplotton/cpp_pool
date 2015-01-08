#include "FragTrap.hpp"
#include <iostream>

int	main()
{
	FragTrap *noName = new FragTrap();
	FragTrap fragTrap("Betty");

	std::cout << std::endl;
	delete noName;

	std::cout << std::endl;
	fragTrap.vaulthunter_dot_exe("Hector");
	fragTrap.vaulthunter_dot_exe("Hector");
	fragTrap.vaulthunter_dot_exe("Hector");
	fragTrap.vaulthunter_dot_exe("Hector");
	fragTrap.vaulthunter_dot_exe("Hector");
	
	std::cout << std::endl;
	fragTrap.rangedAttack("Bernie");
	fragTrap.meleeAttack("Bernie");

	std::cout << std::endl;
	fragTrap.takeDamage(25);
	fragTrap.takeDamage(25);

	std::cout << std::endl;
	fragTrap.beRepaired(25);
	fragTrap.beRepaired(25);

	std::cout << std::endl;
	fragTrap.takeDamage(25);
	fragTrap.takeDamage(25);
	fragTrap.takeDamage(25);
	fragTrap.takeDamage(25);
	fragTrap.takeDamage(25);

	return (0);
}
