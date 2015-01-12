#ifndef GAME_HPP
# define GAME_HPP

#include "AbstractObject.hpp"
#include <iostream>

# define WIDTH  98
# define HEIGHT 48

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
		unsigned int		getScore() const;
		unsigned int		getSpawnRate() const;
		AbstractObject		**getSpaceObjects() const;

		void			deleteWave();
		void			createWave();
		bool			checkCollision();
		void			deleteSpaceObject(unsigned int index);
		void			pushSpaceObject(AbstractObject *& spaceObject);
		AbstractObject	*getSpaceObject(int index) const;

		static unsigned int	m_availableIndex;

	private:
		unsigned int	m_turn;
		unsigned int	m_wave;
		unsigned int	m_turnMax;
		unsigned int	m_waveMax;
		unsigned int	m_score;
		unsigned int	m_spawnRate;
		unsigned int	m_gameSpeed;
		unsigned int	m_nbEnemies;
		unsigned int	m_nbProjectiles;
		unsigned int	m_maxEnemies;
		unsigned int	m_maxProjectiles;
		AbstractObject	**m_spaceObjects;

};

std::ostream & operator<<(std::ostream & o, Game const & i);

#endif /* !GAME_HPP */
