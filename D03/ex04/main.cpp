#include <iostream>
#include "SuperTrap.hpp"

int	main()
{
	std::cout << "===== TEST SUP3R - TP ====" << std::endl;
	std:: cout << "--> no name superTrap" << std::endl;
	SuperTrap *noNameNinja = new SuperTrap();

	std::cout << std::endl;
	delete noNameNinja;

	std:: cout << "--> Edgar superTrap" << std::endl;
	SuperTrap superTrap("Edgar");
	std::cout << std::endl;
	superTrap.healNoob("Hector");
	superTrap.healNoob("Hector");

	std::cout << std::endl;
	superTrap.rangedAttack("Bernie");
	superTrap.meleeAttack("Bernie");

	std::cout << std::endl;
	superTrap.takeDamage(25);
	superTrap.takeDamage(25);
	superTrap.takeDamage(3);

	std::cout << std::endl;
	superTrap.beRepaired(25);
	superTrap.beRepaired(25);
	std::cout << std::endl;

	superTrap.ninjaShoebox((FragTrap &)(superTrap), "enemy");
	std::cout << std::endl;
	std::cout << std::endl;
	return (0);
}
