#ifndef RAMFREE_HPP
# define RAMFREE_HPP

#include "AbstractModule.hpp"

class RamFree : public AbstractModule
{
	public:
		RamFree();
		~RamFree();

		virtual void updateData();
		virtual void initData();
};

#endif /* !RAMFREE_HPP */
