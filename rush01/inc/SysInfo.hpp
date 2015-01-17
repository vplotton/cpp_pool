#ifndef SYSINFO_HPP
# define SYSINFO_HPP

# include <string>

class SysInfo
{
	public:
		SysInfo();
		~SysInfo();

		std::string const &getSysName() const;
		std::string const &getNodeName() const;
		std::string const &getRelease() const;
		std::string const &getVersion() const;
		std::string const &getMachine() const;

	private:
		std::string const m_sysName;
		std::string const m_nodeName;
		std::string const m_release;
		std::string const m_version;
		std::string const m_machine;

		SysInfo(SysInfo const &);
		SysInfo	&operator=(SysInfo const &);
};

#endif /* !SYSINFO_HPP */
