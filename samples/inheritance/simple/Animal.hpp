#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal();
		Animal(Animal const & src);
		~Animal();

		Animal & operator=(Animal const & rhs);

		void	setMyVar(int const var);
		void	setOurVar(int const var);
		int	getMyVar() const;
		int	getOurVar() const;

	protected:
		int	m_ourVar;

	private:
		int	m_myVar;

};

std::ostream & operator<<(std::ostream & o, Animal const & i);

#endif /* !ANIMAL_HPP */
