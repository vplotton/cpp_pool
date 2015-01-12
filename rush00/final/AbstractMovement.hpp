#ifndef ABSTRACTMOVEMENT_HPP
# define ABSTRACTMOVEMENT_HPP

#include "IMovement.hpp"
#include <iostream>

class AbstractMovement : public IMovement
{
	public:
		AbstractMovement(int, int, unsigned int);
		AbstractMovement(AbstractMovement const & src);
		virtual ~AbstractMovement();

		AbstractMovement	&operator=(AbstractMovement const & rhs);
		bool				operator==(IMovement const & rhs);

		static void    (AbstractMovement::*func[])();

		virtual void	setX(int const & x);
		virtual void	setY(int const & y);
		virtual void	setMinX(int const & maxX);
		virtual void	setMinY(int const & maxX);
		virtual void	setMaxX(int const & maxX);
		virtual void	setMaxY(int const & maxY);
		virtual void	setSpeed(int const & speed);
		virtual void	setDirection(e_dir const & direction);
		virtual int		getX() const;
		virtual int		getY() const;
		virtual int		getMinX() const;
		virtual int		getMinY() const;
		virtual int		getMaxX() const;
		virtual int		getMaxY() const;
		virtual int		getSpeed() const;
		virtual e_dir	getDirection() const;
		std::string	getDirName() const;

		static const std::string	typeDirNames[];

		static const unsigned int	m_maxSpeed;

		virtual void	move(e_dir) = 0;
		virtual bool	checkLimits() const;

		virtual void	goUp();
		virtual void	goDown();
		virtual void	goLeft();
		virtual void	goRight();
		virtual void	goForward();


	protected:
		int		m_x;
		int		m_y;
		int		m_minX;
		int		m_minY;
		int		m_maxX;
		int		m_maxY;
		int		m_speed;
		e_dir	m_direction;
		std::string	m_dirName;

	private:
		AbstractMovement();
};

std::ostream & operator<<(std::ostream & o, AbstractMovement const & i);

#endif /* !ABSTRACTMOVEMENT_HPP */
