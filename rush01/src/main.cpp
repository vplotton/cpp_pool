#include <stdexcept>
#include <iostream>
#include <fstream>
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
	std::cout << "Free Swap: " << myFreeSwap / 1000000 << "MB" << std::endl;

	/* Total Virtual Currently Used */
	xsw_usage vmusage;
	size_t size = sizeof(vmusage);
	if(sysctlbyname("vm.swapusage", &vmusage, &size, NULL, 0) != 0)
	{
		std::cerr << "unable to get swap usage by calling sysctlbyname"
			"\"vm.swapusage\",...)" << std::endl;
	}
	std::cout << "Swap usage: " << vmusage.xsu_total / 1000000 << "MB" << std::endl;

	/* Virtual Memory Currently Used by my Process */
	struct task_basic_info t_info;
	mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;

	if (KERN_SUCCESS != task_info(mach_task_self(),
				TASK_BASIC_INFO, (task_info_t)&t_info, 
				&t_info_count))
	{
		return -1;
	}
	std::cout << "Virtual size: " << t_info.virtual_size / 1000000 << "MB" << std::endl;
	std::cout << "Resident size: " << t_info.resident_size / 1000 << "kB" << std::endl;

	/* Total RAM available */
	int mib[2];
	int64_t physical_memory;
	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	size_t length = sizeof(int64_t);
	sysctl(mib, 2, &physical_memory, &length, NULL, 0);

	std::cout << "Ram available: " << physical_memory / 1000000 << "MB" << std::endl;

	// RAM Currently Used
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
			KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
				(host_info64_t)&vm_stats, &count))
	{
		long long free_memory = (int64_t)vm_stats.free_count * (int64_t)page_size;

		long long used_memory = ((int64_t)vm_stats.active_count +
				(int64_t)vm_stats.inactive_count +
				(int64_t)vm_stats.wire_count) *  (int64_t)page_size;
		std::cout << "Free memory: " << free_memory / 1000000 << "MB" << std::endl;
		std::cout << "Used memory: " << used_memory / 1000000 << "MB" << std::endl;
	}
	
	return 0;
}
