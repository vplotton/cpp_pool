#include "modules/Cpu.hpp"

#include <mach/mach_init.h>
#include <mach/mach_error.h>
#include <mach/mach_host.h>
#include <mach/vm_map.h>
#include <sys/types.h>
#include <sys/sysctl.h>


Cpu::Cpu() :
	AbstractModule("Cpu"),
	m_previousTotalTicks(0), m_previousIdleTicks(0)
{
}

Cpu::~Cpu()
{
}

void	Cpu::updateData()
{
	m_infos.at(3).setInfo(getCPULoad() * static_cast<float>(100));
}

void	Cpu::initData()
{
	m_infos.push_back(Info("Model", EInfo::NONE));
	m_infos.at(0).setInfo(getCPUModel());
	
	m_infos.push_back(Info("Frequency", EInfo::HERTZ));
	m_infos.at(1).setInfo(getCPUFrequency());
	
	m_infos.push_back(Info("Core number", EInfo::NONE));
	m_infos.at(2).setInfo(getCoreNumber());

	m_infos.push_back(Info("Activity", EInfo::PERCENTAGE));
	m_infos.at(3).setInfo(getCPULoad() * static_cast<float>(100));
}

std::string Cpu::getCPUModel()
{
	char buf[100];
	size_t buflen = 100;
	sysctlbyname("machdep.cpu.brand_string", &buf, &buflen, NULL, 0);

	std::string output("Intel ");
	output += std::string(buf).substr(18, 8);

	return output;
}

uint64_t	Cpu::getCPUFrequency()
{
	uint64_t freq = 0;
	size_t size = sizeof(freq);

	if (sysctlbyname("hw.cpufrequency", &freq, &size, NULL, 0) < 0)
	{
	}
	return freq;
}

int		Cpu::getCoreNumber()
{
	int		numCPU;
	int		mib[4];
	size_t	len = sizeof(numCPU); 

	mib[0] = CTL_HW;
	mib[1] = HW_AVAILCPU;

	sysctl(mib, 2, &numCPU, &len, NULL, 0);

	return (numCPU);
}

float	Cpu::getCPULoad()
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

float	Cpu::calculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks)
{
	unsigned long long totalTicksSinceLastTime = totalTicks - m_previousTotalTicks;
	unsigned long long idleTicksSinceLastTime  = idleTicks - m_previousIdleTicks;

	float ret = 1.0f - ((totalTicksSinceLastTime > 0) ?
			static_cast<float>(idleTicksSinceLastTime) / totalTicksSinceLastTime : 0); 

	m_previousTotalTicks = totalTicks;
	m_previousIdleTicks  = idleTicks;
	return ret;
}

Cpu::Cpu(Cpu const & src) :
	AbstractModule("Cpu")
{
	(void)src;
}

Cpu	&Cpu::operator=(Cpu const & rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}
