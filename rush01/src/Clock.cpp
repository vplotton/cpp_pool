#include "modules/Clock.hpp"


Clock::Clock() :
	AbstractModule("Clock")
{
}

Clock::~Clock()
{
}

void	Clock::updateData()
{
	std::string date;
	std::string time;

	getDatetime(date, time);

	m_infos.at(0).setInfo(date);
	m_infos.at(1).setInfo(time);
}

void	Clock::initData()
{
	m_infos.push_back(Info("Date", EInfo::NONE));
	m_infos.push_back(Info("Time", EInfo::NONE));
	updateData();
}

void	Clock::getDatetime(std::string &date, std::string &hour)
{
	time_t now = time(0);

	std::string tmp = ctime(&now);

	date = tmp.substr(0, 10) + " " + tmp.substr(20, 4);
	hour = tmp.substr(11, 8);
}

Clock::Clock(Clock const & src) :
	AbstractModule("Clock")
{
	*this = src;
}

Clock & Clock::operator=(Clock const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}
