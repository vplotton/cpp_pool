#ifndef MEMORY_HPP
# define MEMORY_HPP

#include "AbstractModule.hpp"

class Memory : public AbstractModule
{
	public:
		Memory();
		~Memory();

		virtual void updateData();
		virtual void initData();

	private:
		int64_t	getMaxMemory();
		void	getMemoryValues(long long &, long long &);
		Memory(Memory const &);
		Memory &operator=(Memory const &);
};

#endif /* !MEMORY_HPP */
