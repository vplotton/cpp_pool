#ifndef SWAPMEMORY_HPP
# define SWAPMEMORY_HPP

#include "AbstractModule.hpp"

class SwapMemory : public AbstractModule
{
	public:
		SwapMemory();
		~SwapMemory();

		virtual void updateData();
		virtual void initData();

	private:
		unsigned long long	getSwapUsage();
		uint64_t			getTotalSwapMemory();
		SwapMemory(SwapMemory const &);
		SwapMemory	&operator=(SwapMemory const &);

};

#endif /* !SWAPMEMORY_HPP */
