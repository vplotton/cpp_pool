#ifndef CPULOAD_HPP
# define CPULOAD_HPP

# include "AbstractModule.hpp"

class CpuLoad : public AbstractModule
{
	public:
		CpuLoad();
		~CpuLoad();

		virtual void updateData();
		virtual void initData();

	private:
		unsigned long long m_previousTotalTicks;
		unsigned long long m_previousIdleTicks;

		float	getCPULoad();
		float	calculateCPULoad(unsigned long long idleTicks, unsigned long long totalTicks);
};

#endif /* !CPULOAD_HPP */
