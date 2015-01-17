#include "modules/SwapMemory.hpp"
#include <sys/mount.h>
#include <sys/sysctl.h>

SwapMemory::SwapMemory() : AbstractModule("SwapMemoryModule", "B")
{
}

SwapMemory::~SwapMemory()
{
}

void	SwapMemory::updateData()
{
	xsw_usage vmusage;
	size_t size = sizeof(vmusage);

	if(sysctlbyname("vm.swapusage", &vmusage, &size, NULL, 0) != 0)
	{
		/*
		std::cerr << "unable to get swap usage by calling sysctlbyname"
			"\"vm.swapusage\",...)" << std::endl;
		*/
	}

	m_amount = static_cast<unsigned long long>(vmusage.xsu_total);
}

void	SwapMemory::initData()
{
	struct statfs   stats;
	uint64_t        myFreeSwap;
	if (0 == statfs("/", &stats))
	{
		myFreeSwap = (uint64_t)stats.f_bsize * stats.f_bfree;
	}
	m_totalAmount = static_cast<unsigned long long>(myFreeSwap);
}
