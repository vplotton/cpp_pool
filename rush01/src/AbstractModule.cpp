#include "AbstractModule.hpp"
#include <sstream>

char const m_unitRange[] =
{   
	' ',
	'k',
	'M',
	'G',
	'T' 
};

AbstractModule::AbstractModule(std::string const & name, std::string const & unitName) :
	m_name(name), m_unitName(unitName), m_amount(0), m_totalAmount(0)
{
}

AbstractModule::~AbstractModule()
{
}

std::string const &AbstractModule::getUnitName()
{
	return m_unitName;
}

std::string const &AbstractModule::getName()
{
	return m_name;
}

unsigned int	AbstractModule::retrievePercentage()
{
	return (m_amount / m_totalAmount);
}

unsigned long long	AbstractModule::retrieveCurrentAmount()
{
	return m_amount;
}

unsigned long long	AbstractModule::retrieveTotalAmount()
{
	return m_totalAmount;
}

std::string AbstractModule::convertToReadable()
{
	unsigned int		count = 0;
	unsigned long long		value = m_amount;
	std::stringstream		output;

	while (value > 999)
	{
		value /= 1000;
		++count;
		if (count == 4)
			break ;
	}
	output << value << m_unitRange[count] << m_unitName;
	return output.str();
}

AbstractModule::AbstractModule()
{
}

AbstractModule::AbstractModule(AbstractModule const & src)
{
	(void)src;
}

AbstractModule &AbstractModule::operator=(AbstractModule const & rhs)
{
	(void)rhs;
	return (*this);
}
