#include "ZombieEvent.hpp"
#include <cstdlib>

ZombieEvent::ZombieEvent() : m_type("")
{
}

ZombieEvent::~ZombieEvent()
{
}

void	ZombieEvent::setZombieType(std::string type)
{
	m_type = type;
}

Zombie *ZombieEvent::newZombie(std::string name)
{
	Zombie *newZombie = new Zombie();

	newZombie->setName(name);
	newZombie->setType(m_type);

	return (newZombie);
}

std::string genRandom()
{
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	std::string output;

	for (int i = 0; i < 10; ++i)
	{
		output += alphanum[std::rand() % (sizeof(alphanum) - 1)];
	}

	return (output);
}

void	ZombieEvent::randomChump()
{
	Zombie newZombie;

	newZombie.setName(genRandom());
	newZombie.setType("randomChump");
	newZombie.annouce();
}
