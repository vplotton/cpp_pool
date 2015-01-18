#include "modules/Clock.hpp"

#include <iostream>
#include <ctime>
#include <string>

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

void	Clock::getDatetime(std::string &date, std::string &time)
{
	(void)date;
	(void)time;
	/*
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::stringstream	stream;

	stream << 1900 + ltm->tm_year
		<< " " << 1 + ltm->tm_mon
		<< " " <<  ltm->tm_mday;
	date = stream.str();
	stream.clear();

	stream << 1 + ltm->tm_hour
		<< ":" << 1 + ltm->tm_min
		<< ":" << 1 + ltm->tm_sec;
	time = stream.str();
	*/
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
