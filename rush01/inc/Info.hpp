#ifndef INFO_HPP
# define INFO_HPP

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

std::string const unitSuffix[] =
{
	"",
	"B",
	"Hz",
	"%",
};

std::string const unitPrefix[] =
{
	"",
	"k",
	"M",
	"G",
	"T"
};

namespace EInfo {
	enum Type
	{
		NONE = 0,
		BYTES,
		HERTZ,
		PERCENTAGE
	};
};

class Info
{
	public:
		Info(std::string const &name, EInfo::Type type) :
			m_name(name), m_type(type)
	{
	}
		Info(Info const & src) :
			m_name(src.getName()), m_type(src.getType()), m_info(src.getInfo())
		{
			*this = src;
		}

		Info    &operator=(Info const & rhs)
		{
			(void)rhs;
			return *this;
		}
		~Info() {}

		std::string const & getName() const
		{
			return m_name;
		}

		EInfo::Type const &	getType() const
		{
			return m_type;
		}

		std::string const & getInfo() const
		{
			return m_info;
		}

		template <typename T>
		void	setInfo(T const & info)
		{
			std::stringstream       output;

			output << info;
			m_info = output.str();
		}

		std::string const convert()
		{
			if (m_type == EInfo::NONE)
			{
				return m_info;
			}
			double		value = std::atof(m_info.c_str());
			int			count = 0;
			std::stringstream	stream;

			while (value > 1000.001)
			{
				value /= 1000.001;
				++count;
				if (count == 4)
					break ;
			}
			stream.clear();
			stream << value << " "
				<< (m_type == EInfo::BYTES || m_type == EInfo::HERTZ ?
						unitPrefix[count] : "")
				<< unitSuffix[m_type];
			return stream.str();
		}

	private:
		std::string const	m_name;
		EInfo::Type			m_type;
		std::string			m_info;
};

#endif	/* !INFO_HPP */
