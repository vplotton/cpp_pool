#ifndef SQUAD_HPP
# define SQUAD_HPP

#include "ISquad.hpp"
#include "TacticalMarine.hpp"
#include "AssaultTerminator.hpp"
#include <iostream>

class Squad : public ISquad
{
	public:
		Squad();
		Squad(Squad const & src);
		~Squad();

		Squad & operator=(Squad const & rhs);

		virtual int				getCount() const;
		virtual int				push(ISpaceMarine*);
		virtual ISpaceMarine	*getUnit(int);

	private:
		int				m_count;
		ISpaceMarine	**m_squad;


};

/*
std::ostream & operator<<(std::ostream & o, Squad const & i);
*/

#endif /* !SQUAD_HPP */
