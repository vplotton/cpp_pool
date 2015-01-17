#include "Sysinfo.hpp"
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


std::string	initData()
{
	static int count = -1;
	static struct utsname unameData;


	if (++count == 0)
	{
		uname(&unameData);
		return std::string(unameData.sysname);
	}
	else if (count == 1)
	{
		return std::string(unameData.nodename);
	}
	else if (count == 2)
	{
		return std::string(unameData.release);
	}
	else if (count == 3)
	{
		return std::string(unameData.version);
	}
	else if (count == 4)
	{
		return std::string(unameData.machine);
	}
	return ("");
}

SysInfo::SysInfo() :
	m_sysName(initData()), 
	m_nodeName(initData()), 
	m_release(initData()), 
	m_version(initData()), 
	m_machine(initData()) 
{
}

SysInfo::~SysInfo()
{
}

std::string const &SysInfo::getSysName() const
{
	return m_sysName;
}

std::string const &SysInfo::getNodeName() const
{
	return m_nodeName;
}

std::string const &SysInfo::getRelease() const
{
	return m_release;
}

std::string const &SysInfo::getVersion() const
{
	return m_version;
}

std::string const &SysInfo::getMachine() const
{
	return m_machine;
}
