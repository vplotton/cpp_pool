#include "ModuleFactory.hpp"

ModuleFactory::ModuleFactory()
{
}

ModuleFactory::~ModuleFactory()
{
}

std::map<AbstractModule::Type, AbstractModule*>	ModuleFactory::getModules() const
{
	return m_modules;
}

void	ModuleFactory::addModule(AbstractModule::Type type, AbstractModule *module)
{
	m_modules.insert(std::make_pair
			<AbstractModule::Type, AbstractModule*>(type, module));

	m_modules.at(type)->initData();
}

void	ModuleFactory::removeModule(AbstractModule::Type type)
{
	(void)type;
	/* should implement this ... */
}

void	ModuleFactory::enableModule(AbstractModule::Type type)
{
	m_modules.at(type)->enableModule();
}

void    ModuleFactory::disableModule(AbstractModule::Type type)
{
	m_modules.at(type)->disableModule();
}

ModuleFactory::ModuleFactory(ModuleFactory const & src)
{
	*this = src;
}

ModuleFactory	&ModuleFactory::operator=(ModuleFactory const & rhs)
{
	if (this != &rhs)
	{
	}
	return *this;
}
