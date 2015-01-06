#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

#include "Zombie.hpp"

class ZombieHorde
{
	public:
		ZombieHorde(int nbZombies);
		~ZombieHorde();
		void	annouce();

	private:
		int	m_nbZombies;
		Zombie	*m_horde;
};

#endif /* !ZOMBIEHORDE_HPP */
