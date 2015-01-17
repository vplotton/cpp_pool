#include "Game.hpp"
#include "Enemy.hpp"
#include "SpaceShip.hpp"
#include "EnemyMovement.hpp"

unsigned int	const	patternSizes[] =
{
	7
};

Game::Game() :
	m_score(0), m_spawnRate(4), m_spaceObjects(new AbstractObject*[100])
{
	m_turn = 0;
	m_wave = 0;
	m_turnMax = 1000;
	m_waveMax = 2;
	m_gameSpeed = 0;
	m_maxEnemies = 20;
	m_maxProjectiles = 50;
	m_spaceObjects[0] = new SpaceShip("Battlestar", 1, 20, HEIGHT/2);
	for (int i = 1 ; i < 100 ; ++i)
	{
		m_spaceObjects[i] = NULL;
	}
}

Game::Game(Game const & src) :
	m_score(0), m_spawnRate(4), m_spaceObjects(new AbstractObject*[100])
{
	m_turn = 0;
	m_wave = 0;
	m_turnMax = 1000;
	m_waveMax = 2;
	m_gameSpeed = 0;
	m_maxEnemies = 20;
	m_maxProjectiles = 50;
	m_spaceObjects[0] = new SpaceShip("Battlestar", 1, 0, HEIGHT/2);
	for (int i = 1 ; i < 100 ; ++i)
	{
		m_spaceObjects[i] = NULL;
	}
	*this = src;
}

Game::~Game()
{
	for (int i = 0 ; i < 100 ; ++i)
	{
		if (m_spaceObjects[i])
		{
			delete m_spaceObjects[i];
			m_spaceObjects[i] = NULL;
		}
	}
}

Game & Game::operator=(Game const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

void	Game::setScore(unsigned int const score)
{
	m_score = score;
}

void	Game::setSpawnRate(unsigned int const spawnRate)
{
	m_spawnRate = spawnRate;
}

void	Game::setSpaceObjects(AbstractObject **& spaceObjects)
{
	m_spaceObjects = spaceObjects;
}

unsigned int		Game::getScore() const
{
	return m_score;
}

unsigned int		Game::getSpawnRate() const
{
	return m_spawnRate;
}

AbstractObject		**Game::getSpaceObjects() const
{
	return m_spaceObjects;
}

void	Game::deleteWave()
{
		for (int i = 1 ; i < 100 ; ++i)
		{
			deleteSpaceObject(i);
		}
}

void	Game::createWave()
{
	IMovement::e_dir    *wavePattern = new IMovement::e_dir[14];
	wavePattern[0] = IMovement::UP;
	wavePattern[1] = IMovement::UP;
	wavePattern[2] = IMovement::UP;
	wavePattern[3] = IMovement::UP;
	wavePattern[4] = IMovement::DOWN;
	wavePattern[5] = IMovement::DOWN;
	wavePattern[6] = IMovement::DOWN;
	wavePattern[7] = IMovement::DOWN;
	wavePattern[8] = IMovement::UP;
	wavePattern[9] = IMovement::UP;
	wavePattern[10] = IMovement::DOWN;
	wavePattern[11] = IMovement::DOWN;
	wavePattern[12] = IMovement::DOWN;
	wavePattern[13] = IMovement::DOWN;

	if (m_turn > m_turnMax)
	{
		m_wave = (m_wave + 1 < m_waveMax ? m_wave + 1 : 0);
		deleteWave();
		m_nbEnemies = 0;
		m_turn = 0;
		m_gameSpeed = ((m_gameSpeed + 1) >= 8 ? m_gameSpeed : m_gameSpeed + 1);
	}

	if (m_turn % m_spawnRate == 0 && m_nbEnemies < m_maxEnemies)
	{
		AbstractObject *enemy = new Enemy(1, 80, 20);
		if (m_wave == 0)
		{
			((EnemyMovement*)enemy->getMovement())->setPatternSize((unsigned int)12);
			((EnemyMovement*)enemy->getMovement())->setPattern(wavePattern);
		}
		((EnemyMovement*)enemy->getMovement())->setSpeed(m_gameSpeed);
		pushSpaceObject(enemy);
		m_nbEnemies++;
	}
	m_turn++;
}

bool	Game::checkCollision()
{
	int		destroyed[100];
	bool	end = false;

	for (int i = 0 ; i < 100 ; ++i)
	{
		destroyed[i] = -1;
	}

	for (int i = 0 ; i < 100 ; ++i)
	{
		if (m_spaceObjects[i] == NULL)
		{
			continue ;
		}

		for (int j = i + 1 ; j < 100 ; ++j)
		{
			if (m_spaceObjects[j] == NULL)
			{
				continue ;
			}
			if (*m_spaceObjects[i]->getMovement()
					== *m_spaceObjects[j]->getMovement()
					&& i != j)
			{
				if (m_spaceObjects[i]->getType()
						!= m_spaceObjects[j]->getType())
				{
					destroyed[i] = i;
					destroyed[j] = j;
				}
			}
		}
	}

	for (int i = 0 ; i < 100 ; ++i)
	{
		if (destroyed[i] != -1)
		{
			if (m_spaceObjects[i]->getType() == AbstractObject::ENEMY)
			{
				m_score += 10;
			}

			if (i == 0)
			{
				int newLife = m_spaceObjects[i]->getLife() - 1;

				if (newLife == 0)
				{
					deleteSpaceObject(i);
					end = true;
				}
				else
				{
					m_spaceObjects[i]->setLife(newLife);
				}
			}
			else
			{
				deleteSpaceObject(i);
			}
		}
	}
	return (end);
}

void	Game::deleteSpaceObject(unsigned int index)
{
	if (m_spaceObjects[index])
	{
		if (m_spaceObjects[index]->getType() == AbstractObject::ENEMY)
		{
			m_nbEnemies--;
		}
		delete m_spaceObjects[index];
		m_spaceObjects[index] = NULL;
	}
}

AbstractObject *Game::getSpaceObject(int index) const
{
	return m_spaceObjects[index];
}

void	Game::pushSpaceObject(AbstractObject *& spaceObject)
{
	for (int i = 0; i < 100 ; ++i)
	{
		if (!m_spaceObjects[i])
		{
			m_spaceObjects[i] = spaceObject;
			break ;
		}
	}
}

std::ostream & operator<<(std::ostream & o, Game const & i)
{
	AbstractObject  **spaceObjects = i.getSpaceObjects();

	for (int i = 0 ; i < 100 ; ++i)
	{
		if (spaceObjects[i])
		{
			o << *spaceObjects[i];
		}
	}
	return (o);
}
