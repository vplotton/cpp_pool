#ifndef PLAYER_HPP
# define PLAYER_HPP

#include <iostream>

class Player
{
	public:
		Player();
		Player(Player const & src);
		~Player();

		Player & operator=(Player const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Player const & i);

#endif /* !PLAYER_HPP */
