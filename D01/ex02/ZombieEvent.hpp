#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

#include <string>
#include "Zombie.hpp"

class ZombieEvent
{
	public:
		ZombieEvent();
		~ZombieEvent();
		void	setZombieType(std::string type);
		void	randomChump();
		Zombie *newZombie(std::string name);

	private:
		std::string m_type;

};

#endif /* !ZOMBIEEVENT_HPP */
