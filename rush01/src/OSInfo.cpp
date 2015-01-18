#include "modules/OSInfo.hpp"

#include <string>
#include <stdint.h>
#include <unistd.h>
#include <mach/mach.h>
#include <sys/param.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/utsname.h>

OSInfo::OSInfo() :
	AbstractModule("OS Info")
{
}

OSInfo::~OSInfo()
{
}

void	OSInfo::updateData()
{
}

void	OSInfo::initData()
{
	m_infos.push_back(Info("Sysname", EInfo::NONE));
	m_infos.push_back(Info("Machine", EInfo::NONE));

	std::string sysName;
	std::string machine;

	getSysInfos(sysName, machine);
	m_infos.at(0).setInfo(sysName);

	m_infos.at(1).setInfo(machine);
}

void	OSInfo::getSysInfos(std::string &sysName, std::string &machine)
{
	struct utsname unameData;

	uname(&unameData);

	sysName = unameData.sysname;
	machine = unameData.machine;
}

OSInfo::OSInfo(OSInfo const & src) :
	AbstractModule("OS Info")
{
	*this = src;
}


OSInfo & OSInfo::operator=(OSInfo const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}
