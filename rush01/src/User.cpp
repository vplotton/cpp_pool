#include "modules/User.hpp"

#include <cstdlib>
#include <unistd.h>

User::User() :
	AbstractModule("User")
{
}

User::~User()
{
}
void	User::updateData()
{
}

void	User::initData()
{
	m_infos.push_back(Info("Hostname", EInfo::NONE));
	m_infos.at(0).setInfo(getHostName());

	m_infos.push_back(Info("Username", EInfo::NONE));
	m_infos.at(1).setInfo(getUserName());
}

std::string	User::getHostName() const
{
	char	name[80];
	char	*ptr = &name[0];

	gethostname(ptr, 80);
	return std::string(name);
}

char	*User::getUserName() const
{
	return std::getenv("USER");
}

User::User(User const & src) :
	AbstractModule("User")
{
	*this = src;
}

User & User::operator=(User const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}
