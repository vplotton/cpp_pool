#include <iostream>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "NinjaTrap.hpp"

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

	std::cout << std::endl;

	std::cout << "===== TEST NINJ4 - TP ====" << std::endl;
	NinjaTrap *noNameNinja = new NinjaTrap();
	NinjaTrap ninjaTrap("Edgar");

	std::cout << std::endl;
	delete noNameNinja;

	std::cout << std::endl;
	ninjaTrap.healNoob("Hector");
	ninjaTrap.healNoob("Hector");

	std::cout << std::endl;
	ninjaTrap.rangedAttack("Bernie");
	ninjaTrap.meleeAttack("Bernie");

	std::cout << std::endl;
	ninjaTrap.takeDamage(25);
	ninjaTrap.takeDamage(25);
	ninjaTrap.takeDamage(3);

	std::cout << std::endl;
	ninjaTrap.beRepaired(25);
	ninjaTrap.beRepaired(25);
	std::cout << std::endl;

	std::cout << std::endl;
	ninjaTrap.ninjaShoebox(fragTrap, "enemy");
	std::cout << std::endl;
	ninjaTrap.ninjaShoebox(scavTrap, "enemy");
	std::cout << std::endl;
	ninjaTrap.ninjaShoebox(ninjaTrap, "enemy");

	std::cout << std::endl;

	return (0);
}
