#include "modules/CpuLoad.hpp"
#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>


CpuLoad::CpuLoad() : AbstractModule("CpuLoadModule", "%"),
	m_previousTotalTicks(0), m_previousIdleTicks(0)
{
}

CpuLoad::~CpuLoad()
{
}

void	CpuLoad::updateData()
{
	float	cpuLoad = getCPULoad();
	
	m_amount = static_cast<unsigned long long>(cpuLoad * 100);
}

void	CpuLoad::initData()
{
	m_totalAmount = 100;
}

float	CpuLoad::getCPULoad()
{
	host_cpu_load_info_data_t cpuinfo;
	mach_msg_type_number_t count = HOST_CPU_LOAD_INFO_COUNT;

	if (host_statistics(mach_host_self(),
				HOST_CPU_LOAD_INFO,
				(host_info_t)&cpuinfo, &count) == KERN_SUCCESS)
	{   
		unsigned long long totalTicks = 0;

		for(int i = 0 ; i < CPU_STATE_MAX ; i++)
		{   
			totalTicks += cpuinfo.cpu_ticks[i];
		}
		return (calculateCPULoad(cpuinfo.cpu_ticks[CPU_STATE_IDLE], totalTicks));
	}   
	return -1.0f;
}

float	CpuLoad::calculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	unsigned long long totalTicksSinceLastTime = totalTicks - m_previousTotalTicks;
	unsigned long long idleTicksSinceLastTime  = idleTicks - m_previousIdleTicks;

	float ret = 1.0f - ((totalTicksSinceLastTime > 0) ?
		static_cast<float>(idleTicksSinceLastTime) / totalTicksSinceLastTime : 0); 

	m_previousTotalTicks = totalTicks;
	m_previousIdleTicks  = idleTicks;
	return ret;
}

