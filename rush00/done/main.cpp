#include "SpaceShip.hpp"
#include "Enemy.hpp"

int		main()
{
	SpaceShip	*defaultSpaceShip = new SpaceShip;

	SpaceShip	*spaceShip = new SpaceShip("Bastard", 3, 50, 50);

	Weapon		*defaultWeapon = new Weapon(1, "Default");

	Enemy		*enemy = new Enemy(1, 40, 40);

	std::cout << *defaultSpaceShip;
	std::cout << std::endl;
	
	std::cout << *spaceShip;
	std::cout << std::endl;
	
	std::cout << *defaultWeapon;
	std::cout << std::endl;
	std::cout << std::endl;

	spaceShip->setWeapon(defaultWeapon);
	std::cout << *spaceShip;
	std::cout << std::endl;

	std::cout << *enemy;

	return 0;
}
