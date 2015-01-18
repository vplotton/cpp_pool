#include "modules/RamUsed.hpp"
#include <mach/mach.h>
#include <sys/sysctl.h>

RamUsed::RamUsed() : AbstractModule("RamUsedModule", "B")
{
}

RamUsed::~RamUsed()
{
}

void	RamUsed::updateData()
{
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	long long used_memory;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
			KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
				(host_info64_t)&vm_stats, &count))
	{
		used_memory = ((int64_t)vm_stats.active_count +
				(int64_t)vm_stats.inactive_count +
				(int64_t)vm_stats.wire_count) *  (int64_t)page_size;
	}
	m_amount = static_cast<unsigned long long>(used_memory);
}

void	RamUsed::initData()
{
	int mib[2];
	int64_t physical_memory;
	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	size_t length = sizeof(int64_t);
	sysctl(mib, 2, &physical_memory, &length, NULL, 0);

	m_totalAmount = static_cast<unsigned long long>(physical_memory);
}
