#ifndef INFO_HPP
# define INFO_HPP

#include <string>
#include <sstream>

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

template <typename T = std::string>
class Info
{
	public:
		Info(std::string const &name, EInfo::Type type) :
			m_name(name), m_type(type)
	{
	}
		~Info() {}

		std::string const & getName() const
		{
			return m_name;
		}

		T const & getInfo() const
		{
			return m_info;
		}

		void	setInfo(T const & info)
		{
			m_info = info;
		}
		
		template <typename Type>
		std::string const convert(Type const & info)
		{
			double                  value = static_cast<double>(info);
			int                     count = 0;
			std::stringstream       output;

			while (value > 1000.001)
			{
				value /= 1000.001;
				++count;
				if (count == 4)
					break ;
			}
			output << value << " "
				<< (m_type == EInfo::BYTES || m_type == EInfo::HERTZ ?
				unitPrefix[count] : "")
				<< unitSuffix[m_type];
			return output.str();
		}

		std::string const convert(std::string const & info)
		{
			return std::string(info);
		}

	private:
		std::string const	m_name;
		EInfo::Type			m_type;
		T					m_info;

		Info(Info const & src)
		{
			(void)src;
		}
		Info	&operator=(Info const & rhs)
		{
			(void)rhs;
			return *this;
		}
};

template <>
std::string const Info<std::string>::convert<std::string>(std::string const & info)
{
	return std::string(info);
}

#endif	/* !INFO_HPP */
