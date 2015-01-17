#ifndef INTERFACEMODULE_HPP
# define INTERFACEMODULE_HPP

# include <string>

class InterfaceModule
{
	public:
		virtual ~InterfaceModule() {}

		virtual unsigned int	retrievePercentage() = 0;
		virtual unsigned long long	retrieveTotalAmount() = 0;
		virtual unsigned long long	retrieveCurrentAmount() = 0;
		virtual std::string	convertToReadable() = 0;
};

#endif /* !INTERFACEMODULE_HPP */
