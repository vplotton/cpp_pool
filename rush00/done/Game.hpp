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

		bool			checkCollision();
		void			deleteSpaceObject(unsigned int index);
		void			pushSpaceObject(AbstractObject *& spaceObject);
		void			setSpaceObjects(AbstractObject **& spaceObjects);
		AbstractObject	*getSpaceObject(int index) const;
		AbstractObject	**getSpaceObjects() const;

		static unsigned int	m_availableIndex;

	private:
		AbstractObject	**m_spaceObjects;

};

std::ostream & operator<<(std::ostream & o, Game const & i);

#endif /* !GAME_HPP */
