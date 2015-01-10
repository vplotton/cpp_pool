#include "SpaceShip.hpp"

int		main()
{
	SpaceShip	*defaultSpaceShip = new SpaceShip;
	SpaceShip	*spaceShip = new SpaceShip("Bastard", 3, 50, 50);

	std::cout << *defaultSpaceShip;
	std::cout << std::endl;
	std::cout << *spaceShip;
	return 0;
}
