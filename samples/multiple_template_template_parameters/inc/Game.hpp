#ifndef GAME_HPP
# define GAME_HPP

# include "Grid.hpp"
# include <iostream>

class Cell;

template <template <unsigned int, unsigned int, class> class GridPolicy = Grid >
class Game:	public GridPolicy<2, 2, Cell>
{
	public:
		Game() {}
		Game(Game const & src) {}
		~Game() {}

		Game & operator=(Game const & rhs)
		{
			if (this != &rhs)
			{
				m_goban(rhs.m_goban);
			}
			return *this;
		}

		GridPolicy<2, 2, Cell> const			&goban() const
		{ return m_grid; }


		bool		processTurn()
		{
			for (typename GridPolicy<2, 2, Cell>::iterator it = m_grid.begin() ; it != m_grid.end() ; ++it)
			{
				std::cout << "Liberties: " << it->liberties() << std::endl;
			}
			return true;
		}

	private:
		GridPolicy<2, 2, Cell>	m_grid;
};

#endif /* !GAME_HPP */
