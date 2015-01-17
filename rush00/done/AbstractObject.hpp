#ifndef ABSTRACTOBJECT_HPP
# define ABSTRACTOBJECT_HPP

#include "Movement.hpp"
#include <iostream>

class AbstractObject
{
	public:
		enum e_object
		{
			PROJECTILE = 0,
			SPACESHIP,
			DEFAULT,
			ENEMY,
			BOSS
		};

		AbstractObject(e_object type, unsigned int life, int x, int y);
		AbstractObject(AbstractObject const & src);
		virtual ~AbstractObject();

		AbstractObject & operator=(AbstractObject const & rhs);

		void	setType(e_object const &type);
		void	setName(std::string const &name);
		void	setLife(unsigned int const & life);
		void	setMovement(Movement * &movement);
		e_object		getType() const;
		std::string		getName() const;
		unsigned int	getLife() const;
		Movement		*getMovement() const;

		static const std::string typeNames[];

	protected:
		e_object		m_type;
		std::string		m_name;
		unsigned int	m_life;
		Movement		*m_movement;

	private:
		AbstractObject();

};

std::ostream & operator<<(std::ostream & o, AbstractObject const & i);

#endif /* !ABSTRACTOBJECT_HPP */
