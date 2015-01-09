#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>
#include <string>

class Enemy
{
	public:
		Enemy();
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		virtual	~Enemy();

		Enemy & operator=(Enemy const & rhs);
		
		int		getHP() const;
		std::string	getType() const;
		void		setHP(int hitPoints);
		void		setType(std::string const & type);

		virtual void	takeDamage(int) = 0;

	private:
		std::string	m_type;
		int		m_hitPoints;

};

/*
std::ostream & operator<<(std::ostream & o, Enemy const & i);
*/

#endif /* !ENEMY_HPP */
