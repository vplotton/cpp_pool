#include "modules/SwapMemory.hpp"
#include <sys/mount.h>
#include <sys/sysctl.h>

SwapMemory::SwapMemory() :
	AbstractModule("Swap Memory")
{
}

SwapMemory::~SwapMemory()
{
}

void	SwapMemory::updateData()
{
	m_infos.at(1).setInfo(getSwapUsage());
}

void	SwapMemory::initData()
{
	m_infos.push_back(Info("Total", EInfo::OCTET));
	m_infos.at(0).setInfo(getTotalSwapMemory());
	m_infos.push_back(Info("Used", EInfo::OCTET));

	updateData();
}

unsigned long long	SwapMemory::getSwapUsage()
{
	xsw_usage vmusage;
	size_t size = sizeof(vmusage);

	if(sysctlbyname("vm.swapusage", &vmusage, &size, NULL, 0) != 0)
	{
		/*
		 *         std::cerr << "unable to get swap usage by calling sysctlbyname"
		 *                     "\"vm.swapusage\",...)" << std::endl;
		 *                             */
	}

	return static_cast<unsigned long long>(vmusage.xsu_total);
}

uint64_t	SwapMemory::getTotalSwapMemory()
{
	struct statfs   stats;
	uint64_t        myFreeSwap = 0;

	if (0 == statfs("/", &stats))
	{
		myFreeSwap = (uint64_t)stats.f_bsize * stats.f_bfree;
	}
	return myFreeSwap;
}

SwapMemory::SwapMemory(SwapMemory const & src) :
	AbstractModule("Swap Memory")
{
	(void)src;
}

SwapMemory	&SwapMemory::operator=(SwapMemory const & rhs)
{
	(void)rhs;
	return *this;
}
