#ifndef ABSTRACTMODULE
# define ABSTRACTMODULE

# include "InterfaceModule.hpp"

class AbstractModule : public InterfaceModule
{
	public:
		enum Type
		{
			CPU,
			MEMORY
		};
		AbstractModule(std::string const &);
		virtual ~AbstractModule();

		bool						getActivated() const;
		std::string const &			getModuleName() const;
		std::vector<Info> const &	getInfos() const;

		virtual void	updateData() = 0;
		virtual void	initData() = 0;

	protected:
		std::vector<Info>	m_infos;
		std::string const	m_moduleName;
		bool				m_isActivated;

		AbstractModule();
		AbstractModule(AbstractModule const &);
		AbstractModule &operator=(AbstractModule const &);
};

#endif /* !ABSTRACTMODULE */
