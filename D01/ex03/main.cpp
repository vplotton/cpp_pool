#include "ZombieHorde.hpp"

int		main()
{
	ZombieHorde *horde = new ZombieHorde(3);

	horde->annouce();

	delete horde;

	return (0);
}
