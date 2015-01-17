#ifndef ABSTRACTMODULE
# define ABSTRACTMODULE

# include "InterfaceModule.hpp"
# include <vector>

class AbstractModule : public InterfaceModule
{
	public:
		AbstractModule(std::string const &, std::string const & unitName);
		~AbstractModule();

		std::string const &	getUnitName();
		std::string const &	getName();

		unsigned int	retrievePercentage();
		unsigned long long	retrieveTotalAmount();
		unsigned long long	retrieveCurrentAmount();
		std::string	convertToReadable();

		virtual void	updateData() = 0;
		virtual void	initData() = 0;

	protected:
		std::string const	m_name;
		std::string const	m_unitName;
		unsigned long long	m_amount;
		unsigned long long	m_totalAmount;

		AbstractModule();
		AbstractModule(AbstractModule const &);
		AbstractModule &operator=(AbstractModule const &);
};

#endif /* !ABSTRACTMODULE */
