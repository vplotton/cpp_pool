#include "Game.hpp"
#include "SpaceShip.hpp"

Game::Game() : m_spaceObjects(new AbstractObject*[100])
{
	m_spaceObjects[0] = new SpaceShip("Battlestar", 1, 20, HEIGHT/2);
	for (int i = 1 ; i < 100 ; ++i)
	{
		m_spaceObjects[i] = NULL;
	}
}

Game::Game(Game const & src) : m_spaceObjects(new AbstractObject*[100])
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
}

Game & Game::operator=(Game const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
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
			if (i == 0)
			{
				end = true;
			}
			deleteSpaceObject(i);
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

void	Game::setSpaceObjects(AbstractObject **& spaceObjects)
{
	m_spaceObjects = spaceObjects;
}

AbstractObject  **Game::getSpaceObjects() const
{
	return m_spaceObjects;
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
