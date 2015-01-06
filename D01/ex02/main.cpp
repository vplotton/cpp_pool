#include "ZombieEvent.hpp"
#include <iostream>

int	main()
{
	ZombieEvent zombieCreator;
	Zombie *zombieWithoutType;
	Zombie *edgar;
	
	zombieWithoutType = zombieCreator.newZombie("ZombieWithoutType");
	zombieWithoutType->annouce();
	std::cout << std::endl;

	zombieCreator.setZombieType("intellectual");
	edgar = zombieCreator.newZombie("edgar");
	edgar->annouce();
	std::cout << std::endl;

	zombieCreator.randomChump();
	std::cout << std::endl;

	delete zombieWithoutType;
	std::cout << std::endl;

	delete edgar;
	std::cout << std::endl;
	return (0);
}
