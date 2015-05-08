#ifndef PAWN_HPP
# define PAWN_HPP

# include "InterfacePlayer.hpp"
# include <iostream>

class Pawn
{
	public:
		Pawn();
		Pawn(InterfacePlayer *);
		Pawn(unsigned int const &, InterfacePlayer *);
		Pawn(Pawn const & src);
		~Pawn();

		Pawn & operator=(Pawn const & rhs);

		unsigned int const	&id() const;
		InterfacePlayer		*player() const;
		bool const			&used() const;
		bool const			&captured() const;
		void				id(unsigned int const &);
		void				player(InterfacePlayer*);
		void				used(bool);
		void				captured(bool);

		static unsigned int currentId;

	private:
		unsigned int		m_id;
		InterfacePlayer		*m_player;
		bool			m_used;
		bool			m_captured;
};

std::ostream & operator<<(std::ostream & o, Pawn const & i);

#endif /* !PAWN_HPP */
