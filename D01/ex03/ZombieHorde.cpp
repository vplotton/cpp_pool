#include "ZombieHorde.hpp"
#include <string>
#include <cstdlib>
#include <iostream>

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


ZombieHorde::ZombieHorde(int nbZombies) : m_nbZombies(nbZombies), m_horde(new Zombie[nbZombies])
{
	for (int i = 0 ; i < m_nbZombies ; ++i)
	{
		m_horde[i].setName(genRandom());
		m_horde[i].setType("randomChump");
	}
	std::cout << nbZombies << " zombies just have been created" << std::endl;
	std::cout << std::endl;
}

ZombieHorde::~ZombieHorde()
{
	delete [] m_horde;
	std::cout << m_nbZombies << " zombies just have been demolished." << std::endl;
}

void	ZombieHorde::annouce()
{
	for (int i = 0 ; i < m_nbZombies ; ++i)
	{
		m_horde[i].annouce();
	}
	std::cout << std::endl;
}
