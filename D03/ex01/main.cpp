#include <iostream>
#include "FragTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	std::cout << "===== TEST CL4P - TP ====" << std::endl;
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
	fragTrap.takeDamage(3);

	std::cout << std::endl;
	fragTrap.beRepaired(25);
	fragTrap.beRepaired(25);

	std::cout << std::endl;
	fragTrap.takeDamage(25);
	fragTrap.takeDamage(25);
	fragTrap.takeDamage(25);
	fragTrap.takeDamage(25);
	fragTrap.takeDamage(25);


	std::cout << "===== TEST SC4V - TP ====" << std::endl;
	ScavTrap *noName = new ScavTrap();
	ScavTrap scavTrap("Betty");

	std::cout << std::endl;
	delete noName;

	std::cout << std::endl;
	scavTrap.challengeNewcomer("Hector");
	scavTrap.challengeNewcomer("Hector");
	scavTrap.challengeNewcomer("Hector");
	scavTrap.challengeNewcomer("Hector");
	scavTrap.challengeNewcomer("Hector");

	std::cout << std::endl;
	scavTrap.rangedAttack("Bernie");
	scavTrap.meleeAttack("Bernie");

	std::cout << std::endl;
	scavTrap.takeDamage(25);
	scavTrap.takeDamage(25);
	scavTrap.takeDamage(3);

	std::cout << std::endl;
	scavTrap.beRepaired(25);
	scavTrap.beRepaired(25);


	return (0);
}
