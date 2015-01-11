#ifndef MOVEMENT_HPP
# define MOVEMENT_HPP

#include <iostream>

class Movement
{
	public:
		enum e_dir
		{
			UP = 0,
			DOWN,
			LEFT,
			RIGHT
		};

		Movement();
		Movement(int, int, int);
		Movement(Movement const & src);
		virtual ~Movement();

		Movement & operator=(Movement const & rhs);

		void	setX(int const & x);
		void	setY(int const & y);
		void	setSpeed(int const & speed);
		void	setDirection(e_dir const & direction);
		int		getX() const;
		int		getY() const;
		int		getSpeed() const;
		e_dir	getDirection() const;
		std::string	getDirName() const;

		void	goUp();
		void	goDown();
		void	goLeft();
		void	goRight();

		static const std::string typeDirNames[];

	private:
		int		m_x;
		int		m_y;
		int		m_speed;
		e_dir	m_direction;
		std::string	m_dirName;
};

std::ostream & operator<<(std::ostream & o, Movement const & i);

#endif /* !MOVEMENT_HPP */
