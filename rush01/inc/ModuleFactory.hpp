#ifndef MODULEFACTORY_HPP
# define MODULEFACTORY_HPP

#include "AbstractModule.hpp"
#include <map>

class ModuleFactory
{
	public:
		ModuleFactory();
		~ModuleFactory();

		std::map<AbstractModule::Type, AbstractModule*>	getModules() const;

		void	addModule(AbstractModule::Type, AbstractModule*);
		void	removeModule(AbstractModule::Type);
		void	enableModule(AbstractModule::Type);
		void	disableModule(AbstractModule::Type);

	private:
		std::map<AbstractModule::Type, AbstractModule*>	m_modules;
		ModuleFactory(ModuleFactory const &);
		ModuleFactory	&operator=(ModuleFactory const &);
};

#endif /* !MODULEFACTORY_HPP */
