#ifndef CPU_HPP
# define CPU_HPP

# include "AbstractModule.hpp"

class Cpu : public AbstractModule
{
	public:
		Cpu();
		~Cpu();

		virtual void updateData();
		virtual void initData();

	private:
		unsigned long long m_previousTotalTicks;
		unsigned long long m_previousIdleTicks;

		std::string	getCPUModel();
		uint64_t	getCPUFrequency();
		float	getCPULoad();
		float	calculateCPULoad(unsigned long long idleTicks,
					unsigned long long totalTicks);
		int		getCoreNumber();

		Cpu(Cpu const &);
		Cpu	&operator=(Cpu const &);
};

#endif /* !CPU_HPP */
