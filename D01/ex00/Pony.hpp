#ifndef PONY_HPP
# define PONY_HPP

#include <string>

class Pony
{
	public:
		Pony();
		~Pony();
		void		setName(std::string name);
		std::string	getName();

	private:
		std::string m_name;
};

#endif /* !PONY_HPP */
