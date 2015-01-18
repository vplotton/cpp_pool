#ifndef OSINFO_HPP
# define OSINFO_HPP

#include "AbstractModule.hpp"
#include <iostream>

class OSInfo : public AbstractModule
{
	public:
		OSInfo();
		~OSInfo();

		virtual void    updateData();
		virtual void    initData();

	private:
		void    getSysInfos(std::string &, std::string &);
		OSInfo(OSInfo const & src);
		OSInfo & operator=(OSInfo const & rhs);
};

#endif /* !OSINFO_HPP */
