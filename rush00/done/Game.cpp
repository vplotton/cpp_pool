#include "Game.hpp"
#include "SpaceShip.hpp"

Game::Game() : m_score(0), m_spawnRate(10), m_spaceObjects(new AbstractObject*[100])
{
	m_spaceObjects[0] = new SpaceShip("Battlestar", 1, 20, HEIGHT/2);
	for (int i = 1 ; i < 100 ; ++i)
	{
		m_spaceObjects[i] = NULL;
	}
}

Game::Game(Game const & src) : m_score(0), m_spawnRate(10), m_spaceObjects(new AbstractObject*[100])
{
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

unsigned int const	Game::getScore() const
{
	return m_score;
}

unsigned int const	Game::getSpawnRate() const
{
	return m_spawnRate;
}

AbstractObject		**Game::getSpaceObjects() const
{
	return m_spaceObjects;
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

			/*
			std::cout << (*m_spaceObjects[i]->getMovement()
				== *m_spaceObjects[j]->getMovement() ? "true" : "false")
					<< std::endl;
			std::cout << "i: " << i << std::endl;
			std::cout << "j: " << j << std::endl;
			*/
			if (*m_spaceObjects[i]->getMovement()
					== *m_spaceObjects[j]->getMovement() && i != j)
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
		/*	
		std::cout << m_spaceObjects[index]->getName() << std::endl;
		*/	
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
