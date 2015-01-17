#ifndef GAME_HPP
# define GAME_HPP

#include "AbstractObject.hpp"
#include <iostream>


# define WIDTH 100
# define HEIGHT 100

class Game
{
	public:
		Game();
		Game(Game const & src);
		~Game();

		Game & operator=(Game const & rhs);

		void	setScore(unsigned int const score);
		void	setSpawnRate(unsigned int const spawnRate);
		void	setSpaceObjects(AbstractObject **& spaceObjects);
		unsigned int 	getScore() const;
		unsigned int 	getSpawnRate() const;
		AbstractObject		**getSpaceObjects() const;

		bool			checkCollision();
		void			deleteSpaceObject(unsigned int index);
		void			pushSpaceObject(AbstractObject *& spaceObject);
		AbstractObject	*getSpaceObject(int index) const;

		static unsigned int	m_availableIndex;

	private:
		unsigned int	m_score;
		unsigned int	m_spawnRate;
		AbstractObject	**m_spaceObjects;

};

std::ostream & operator<<(std::ostream & o, Game const & i);

#endif /* !GAME_HPP */
