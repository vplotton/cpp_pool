#ifndef NETWORK_HPP
# define NETWORK_HPP

#include "AbstractModule.hpp"

class Network : public AbstractModule
{
	public:
		Network();
		~Network();

		virtual void    updateData();
		virtual void    initData();

	private:
		unsigned long long m_previousTotalInput;
		unsigned long long m_previousTotalOutput;

		void	getInOutput(unsigned long long &, unsigned long long &);
		unsigned long long  calculateNetworkInput(unsigned long long);
		unsigned long long  calculateNetworkOutput(unsigned long long);

		Network(Network const & src);
		Network & operator=(Network const & rhs);
};

#endif /* !NETWORK_HPP */
