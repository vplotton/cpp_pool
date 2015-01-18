#ifndef INFO_HPP
# define INFO_HPP

#include <cstdlib>
#include <string>
#include <sstream>
#include <iostream>

std::string const unitSuffix[] =
{
	"",
	"o",
	"B",
	"Hz",
	"%%",
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
		OCTET,
		BYTES,
		HERTZ,
		PERCENTAGE
	};
};

class Info
{
	public:
		Info(std::string const &name, EInfo::Type type);

		Info(Info const & src);

		Info    &operator=(Info const & rhs);
		~Info();

		std::string const & getName() const;

		EInfo::Type const &	getType() const;

		std::string const & getInfo() const;

		template <typename T>
		void	setInfo(T const & info)
		{
			std::stringstream       output;

			output << info;
			m_info = output.str();
		}

		std::string const convert();

	private:
		std::string const	m_name;
		EInfo::Type			m_type;
		std::string			m_info;
};

#endif	/* !INFO_HPP */
