#ifndef MOVEMENT_HPP
# define MOVEMENT_HPP

#include <iostream>

class Movement
{
	public:
		Movement();
		Movement(int, int, int);
		Movement(Movement const & src);
		virtual ~Movement();

		Movement & operator=(Movement const & rhs);

		void	setX(int const & x);
		void	setY(int const & y);
		void	setSpeed(int const & speed);
		int		getX() const;
		int		getY() const;
		int		getSpeed() const;

		void	goUp();
		void	goDown();
		void	goLeft();
		void	goRight();

	private:
		int		m_x;
		int		m_y;
		int		m_speed;
};

std::ostream & operator<<(std::ostream & o, Movement const & i);

#endif /* !MOVEMENT_HPP */
