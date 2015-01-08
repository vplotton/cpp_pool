#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
	std::cout << "===== TEST CL4P - TP ====" << std::endl;
	FragTrap *noNameTrap = new FragTrap();
	FragTrap fragTrap("Betty");

	std::cout << std::endl;
	delete noNameTrap;

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

	std::cout << std::endl;

	std::cout << "===== TEST SC4V - TP ====" << std::endl;
	ScavTrap *noNameScav = new ScavTrap();
	ScavTrap scavTrap("Edgar");

	std::cout << std::endl;
	delete noNameScav;

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

	std::cout << std::endl;

	return (0);
}
