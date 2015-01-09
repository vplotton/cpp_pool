#include "PlasmaRifle.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"

int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;

	if (b == NULL)
	{
		std::cout << "enemy is NULL" << std::endl;
	}
	else
	{
		std::cout << "enemy is not NULL" << std::endl;
	}
	while (b && b->getHP())
	{
		zaz->attack(b);
		zaz->recoverAP();
	}

	if (b == NULL)
	{
		std::cout << "enemy is NULL" << std::endl;
	}
	else
	{
		std::cout << "enemy is not NULL" << std::endl;
	}
	return 0;
}
