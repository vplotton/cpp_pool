#ifndef IMOVEMENT_HPP
# define IMOVEMENT_HPP

#include <string>

class IMovement
{
	public:
		enum e_dir
		{
			UP = 0,
			DOWN,
			LEFT,
			RIGHT
		};

		virtual ~IMovement() {};

		virtual bool	operator==(IMovement const & rhs) = 0;

		virtual void	setX(int const & x) = 0;
		virtual void	setY(int const & y) = 0;
		virtual void	setMinX(int const & maxX) = 0;
		virtual void	setMinY(int const & maxX) = 0;
		virtual void	setMaxX(int const & maxX) = 0;
		virtual void	setMaxY(int const & maxY) = 0;
		virtual void	setSpeed(int const & speed) = 0;
		virtual void	setDirection(e_dir const & direction) = 0;
		virtual int			getX() const = 0;
		virtual int			getY() const = 0;
		virtual int			getMinX() const = 0;
		virtual int			getMinY() const = 0;
		virtual int			getMaxX() const = 0;
		virtual int			getMaxY() const = 0;
		virtual int			getSpeed() const = 0;
		virtual e_dir		getDirection() const = 0;
		virtual std::string	getDirName() const = 0;

		virtual void	move(e_dir) = 0;
		virtual bool	checkLimits() const = 0;

		virtual void	goUp() = 0;
		virtual void	goDown() = 0;
		virtual void	goLeft() = 0;
		virtual void	goRight() = 0;
		virtual void	goForward() = 0;
};

#endif /* !IMOVEMENT_HPP */
