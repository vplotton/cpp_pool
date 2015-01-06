#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain
{
	public:
		Brain();
		~Brain();
		std::string identify() const;

	private:
		const void *m_address;
};

#endif /* ~BRAIN_HPP */
