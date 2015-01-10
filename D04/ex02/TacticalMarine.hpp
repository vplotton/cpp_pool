#ifndef TACTICALMARINE_HPP
# define TACTICALMARINE_HPP

#include "ISpaceMarine.hpp"
#include <iostream>

class TacticalMarine : public ISpaceMarine
{
	public:
		TacticalMarine();
		TacticalMarine(TacticalMarine const & src);
		~TacticalMarine();

		TacticalMarine & operator=(TacticalMarine const & rhs);

		virtual ISpaceMarine* clone() const;

		virtual void battleCry() const;
		virtual void rangedAttack() const;
		virtual void meleeAttack() const;
	private:

};

/*
std::ostream & operator<<(std::ostream & o, TacticalMarine const & i);
*/

#endif /* !TACTICALMARINE_HPP */
