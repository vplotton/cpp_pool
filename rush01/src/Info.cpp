#include "Info.hpp"

Info::Info(std::string const &name, EInfo::Type type) :
	m_name(name), m_type(type)
{
}

Info::Info(Info const & src) :
	m_name(src.getName()), m_type(src.getType()), m_info(src.getInfo())
{
	*this = src;
}

Info    &Info::operator=(Info const & rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}

Info::~Info()
{
}

std::string const & Info::getName() const
{
	return m_name;
}

EInfo::Type const & Info::getType() const
{
	return m_type;
}

std::string const & Info::getInfo() const
{
	return m_info;
}

std::string const Info::convert()
{
	if (m_type == EInfo::NONE)
	{
		return m_info;
	}
	double      value = std::atof(m_info.c_str());
	int         count = 0;
	std::stringstream   stream;

	while (value > 1000.001)
	{
		value /= 1000.001;
		++count;
		if (count == 5)
			break ;
	}
	stream.clear();
	stream << value << " "
		<< (m_type == EInfo::BYTES
				|| m_type == EInfo::HERTZ
				|| m_type == EInfo::OCTET ?
				unitPrefix[count] : "")
		<< unitSuffix[m_type];
	return stream.str();
}
