#include "SpaceShip.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include <unistd.h>

int		main()
{
	Game			*game = new Game;
	AbstractObject	*enemy = new Enemy(1, 32, 50);

	game->pushSpaceObject(enemy);
	
	std::cout << "==============\n";
	std::cout << *game;
	std::cout << "==============\n";
	std::cout << *enemy;
	enemy->getMovement()->goForward();
	std::cout << "==============\n";
	std::cout << *enemy;
	enemy->getMovement()->goForward();
	std::cout << "==============\n";
	std::cout << *enemy;
	std::cout << "==============\n";
/*	std::cout << *game;*/

	int		turn = 0;
	SpaceShip *ship = (SpaceShip*)game->getSpaceObject(0);
	AbstractObject *projectile = ship->getWeapon()->shoot(ship->getMovement());
	game->pushSpaceObject(projectile);
	while (game->checkCollision() == false)
	{
		AbstractObject  **spaceObjects = game->getSpaceObjects();
		std::cout << "TURN: " << turn++ << std::endl;
		std::cout << "enemy address: " << enemy << std::endl;

		for (int i = 0; i < 100 ; ++i)
		{
			if (spaceObjects[i])
			{
				spaceObjects[i]->getMovement()->goForward();
				std::cout << "==============\n";
				std::cout << *spaceObjects[i];
			}
		}

		std::cout << "END OF TURN" << std::endl;
		sleep(1);
	}


	/*
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
	   */
	return 0;
}
