#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void	announce();
		void	setName(std::string name);
		void	setType(std::string type);
		std::string getName();
		std::string getType();

	private:
		std::string m_name;
		std::string m_type;
};

#endif /* !ZOMBIE_HPP */
