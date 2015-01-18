#ifndef INTERFACEMODULE_HPP
# define INTERFACEMODULE_HPP

# include "Info.hpp"
# include <string>
# include <vector>

class InterfaceModule
{
	public:
		virtual ~InterfaceModule() {}

		virtual bool                        getActivated() const = 0;
		virtual std::string const &         getModuleName() const = 0;
		virtual std::vector<Info> const &   getInfos() const = 0;

		virtual void    updateData() = 0;
		virtual void    initData() = 0;

};

#endif /* !INTERFACEMODULE_HPP */
