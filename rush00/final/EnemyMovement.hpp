#ifndef ENEMYMOVEMENT_HPP
# define ENEMYMOVEMENT_HPP

#include "AbstractMovement.hpp"
#include <iostream>

class EnemyMovement : public AbstractMovement
{
	public:
		EnemyMovement(int, int, int, unsigned int, e_dir *&);
		EnemyMovement(EnemyMovement const & src);
		virtual ~EnemyMovement();

		virtual EnemyMovement	&operator=(EnemyMovement const & rhs);
		virtual bool			operator==(IMovement const & rhs);

		virtual void	move(e_dir);

		void	setPatternSize(unsigned int);
		void	setPattern(e_dir *& pattern);
		unsigned int		getPatternSize() const;
		IMovement::e_dir	*getPattern() const;

		void			randMove();


	private:
		unsigned int	m_patternSize;
		unsigned int 	m_curPatElt;
		unsigned int 	m_turn;
		e_dir			*m_pattern;
		EnemyMovement();
};

std::ostream & operator<<(std::ostream & o, EnemyMovement const & i);

#endif /* !ENEMYMOVEMENT_HPP */
