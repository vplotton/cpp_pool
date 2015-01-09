#ifndef ASSAULTTERMINATOR_HPP
# define ASSAULTTERMINATOR_HPP

#include <iostream>

class AssaultTerminator
{
	public:
		AssaultTerminator();
		AssaultTerminator(AssaultTerminator const & src);
		~AssaultTerminator();

		AssaultTerminator & operator=(AssaultTerminator const & rhs);

		virtual void battleCry() const;
		virtual void rangedAttack() const;
		virtual void meleeAttack() const;

	private:

};

std::ostream & operator<<(std::ostream & o, AssaultTerminator const & i);

#endif /* !ASSAULTTERMINATOR_HPP */
