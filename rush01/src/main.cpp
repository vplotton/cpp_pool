#include <stdexcept>
#include <iostream>
#include <fstream>
#include <string>
#include <stdint.h>
#include <unistd.h>
#include<mach/mach.h>
#include <sys/param.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/sysctl.h>
#include <sys/utsname.h>

struct utsname unameData;

uint64_t get_cpu_freq(void)
{
	uint64_t freq = 0;
	size_t size = sizeof(freq);

	if (sysctlbyname("hw.cpufrequency", &freq, &size, NULL, 0) < 0)
	{
		throw (std::runtime_error("sysctl error."));
	}
	return freq;
}

int		main()
{
	std::cout << "Welcome to GKrellM" << std::endl;
	std::cout << std::endl;

	/* sys info */
	uname(&unameData);

	std::cout << "Sysname: " << unameData.sysname << std::endl;
	std::cout << "Nodename: " << unameData.nodename << std::endl;
	std::cout << "Release: " << unameData.release << std::endl;
	std::cout << "Version: " << unameData.version << std::endl;
	std::cout << "Machine: " << unameData.machine << std::endl;

	std::cout << std::endl;
	/* cpu freq */
	try
	{
		std::cout << "Cpu freq: "
			<< (get_cpu_freq() / 1000000)
			<< "MHz"
			<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	/* Total Virtual Memory */
	struct statfs	stats;
	uint64_t		myFreeSwap;
	if (0 == statfs("/", &stats))
	{
		myFreeSwap = (uint64_t)stats.f_bsize * stats.f_bfree;
	}
	std::cout << "Free Swap: " << myFreeSwap << std::endl;

	/* Total Virtual Currently Used */
	xsw_usage vmusage;
	size_t size = sizeof(vmusage);
	if( sysctlbyname("vm.swapusage", &vmusage, &size, NULL, 0)!=0 )
	{
		std::cerr << "unable to get swap usage by calling sysctlbyname"
			"\"vm.swapusage\",...)" << std::endl;
	}

	/* Virtual Memory Currently Used by my Process */
	struct task_basic_info t_info;
	mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;

	if (KERN_SUCCESS != task_info(mach_task_self(),
				TASK_BASIC_INFO, (task_info_t)&t_info, 
				&t_info_count))
	{
		return -1;
	}


	return 0;
}
