#include "Game.hpp"

Game::Game()
{
}

Game::Game(Game const & src)
{
	*this = src;
}

Game::~Game()
{
}

Game & Game::operator=(Game const & rhs)
{
	if (this != &rhs)
	{
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

std::ostream & operator<<(std::ostream & o, Game const & i)
{
	o << "Don't forget to change this.";
	return (o);
}
