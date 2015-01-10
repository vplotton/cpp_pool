#ifndef ABSTRACTOBJECT_HPP
# define ABSTRACTOBJECT_HPP

#include "Movement.hpp"
#include "Interact.hpp"
#include <iostream>

class AbstractObject
{
	public:
		enum e_type
		{
			PROJECTILE = 0,
			SPACESHIP,
			DEFAULT,
			ENEMY
		};

		static std::string const typeNames[];

		AbstractObject(e_type type, unsigned int life, int x, int y);
		AbstractObject(AbstractObject const & src);
		virtual ~AbstractObject();

		AbstractObject & operator=(AbstractObject const & rhs);

		void	setType(e_type const &type);
		void	setName(std::string const &name);
		void	setLife(unsigned int const & life);
		void	setMovement(Movement * &movement);
		void	setInteract(Interact * &interact);
		e_type			getType() const;
		std::string		getName() const;
		unsigned int	getLife() const;
		Movement		*getMovement() const;
		Interact		*getInteract() const;

	protected:
		e_type			m_type;
		std::string		m_name;
		unsigned int	m_life;
		Movement		*m_movement;
		Interact		*m_interact;

	private:
		AbstractObject();

};

std::ostream & operator<<(std::ostream & o, AbstractObject const & i);

#endif /* !ABSTRACTOBJECT_HPP */
