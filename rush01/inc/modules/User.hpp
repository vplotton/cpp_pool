#ifndef USER_HPP
# define USER_HPP

#include "AbstractModule.hpp"
#include <iostream>

class User : public AbstractModule
{
	public:
		User();
		~User();

		virtual void    updateData();
		virtual void    initData();

	private:
		std::string	getHostName() const;
		char    *getUserName() const;

		User(User const & src);
		User & operator=(User const & rhs);
};


#endif /* !USER_HPP */
