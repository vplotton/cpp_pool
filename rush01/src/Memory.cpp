#include "modules/Memory.hpp"

#include <mach/mach.h>
#include <sys/sysctl.h>

Memory::Memory():
	AbstractModule("Memory Module")
{
}

Memory::~Memory()
{
}

void	Memory::updateData()
{
	long long free;
	long long used;
	getMemoryValues(free, used);
	
	m_infos.at(1).setInfo(free);
	m_infos.at(2).setInfo(used);
}

void	Memory::initData()
{
	m_infos.push_back(Info("Total", EInfo::BYTES));
	m_infos.at(0).setInfo(getMaxMemory());
	m_infos.push_back(Info("Free", EInfo::BYTES));
	m_infos.push_back(Info("Used", EInfo::BYTES));

	updateData();
}

int64_t	Memory::getMaxMemory()
{
	int mib[2];
	int64_t physical_memory;
	mib[0] = CTL_HW;
	mib[1] = HW_MEMSIZE;
	size_t length = sizeof(int64_t);
	sysctl(mib, 2, &physical_memory, &length, NULL, 0);

	return (physical_memory);
}

void	Memory::getMemoryValues(long long &free, long long &used)
{
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
		used = ((int64_t)vm_stats.active_count +
				(int64_t)vm_stats.inactive_count +
				(int64_t)vm_stats.wire_count) *  (int64_t)page_size;

		free = (int64_t)vm_stats.free_count * (int64_t)page_size;
	}
}

Memory::Memory(Memory const & src) : AbstractModule("Memory Copy")
{
	(void)src;
}

Memory	&Memory::operator=(Memory const & rhs)
{
	(void)rhs;
	return *this;
}
