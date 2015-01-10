#ifndef GAME_HPP
# define GAME_HPP

#include <iostream>

class Game
{
	public:
		Game();
		Game(Game const & src);
		~Game();

		Game & operator=(Game const & rhs);

	private:

};

std::ostream & operator<<(std::ostream & o, Game const & i);

#endif /* !GAME_HPP */
