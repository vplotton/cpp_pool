#ifndef PLAYERMOVEMENT_HPP
# define PLAYERMOVEMENT_HPP

#include "AbstractMovement.hpp"
#include <iostream>

class PlayerMovement : public AbstractMovement
{
	public:
		PlayerMovement(int, int);
		PlayerMovement(PlayerMovement const & src);
		virtual ~PlayerMovement();

		virtual PlayerMovement	&operator=(PlayerMovement const & rhs);
		virtual bool			operator==(IMovement const & rhs);

		virtual void	move(e_dir);

	private:
		PlayerMovement();
};

std::ostream & operator<<(std::ostream & o, PlayerMovement const & i);

#endif /* !PLAYERMOVEMENT_HPP */
