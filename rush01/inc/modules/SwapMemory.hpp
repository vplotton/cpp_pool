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
};

#endif /* !SWAPMEMORY_HPP */
