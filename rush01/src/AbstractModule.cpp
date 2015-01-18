#include "AbstractModule.hpp"
#include <sstream>

AbstractModule::AbstractModule(std::string const & moduleName) :
	m_moduleName(moduleName)
{
}

AbstractModule::~AbstractModule()
{
}

bool						AbstractModule::getActivated() const
{
	return m_isActivated;
}

std::string const &			AbstractModule::getModuleName() const
{
	return m_moduleName;
}

std::vector<Info> const &   AbstractModule::getInfos() const
{
	return m_infos;
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
