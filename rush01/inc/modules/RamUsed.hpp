#ifndef RAMUSED_HPP
# define RAMUSED_HPP

#include "AbstractModule.hpp"

class RamUsed : public AbstractModule
{
	public:
		RamUsed();
		~RamUsed();

		virtual void updateData();
		virtual void initData();
};

#endif /* !RAMUSED_HPP */
