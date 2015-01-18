#include "modules/Cpu.hpp"
#include "modules/user.hpp"
#include "modules/Clock.hpp"
#include "modules/OSInfo.hpp"
#include "modules/Memory.hpp"
#include "modules/Network.hpp"
#include "modules/SwapMemory.hpp"
#include "ModuleFactory.hpp"

#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>

void	initModules(ModuleFactory &factory)
{
	factory.addModule(AbstractModule::CPU, new Cpu());
	factory.addModule(AbstractModule::MEMORY, new Memory());
	factory.addModule(AbstractModule::SWAPMEMORY, new SwapMemory());
	factory.addModule(AbstractModule::CLOCK, new Clock());
	factory.addModule(AbstractModule::USER, new User());
	factory.addModule(AbstractModule::OSINFO, new OSInfo());
	factory.addModule(AbstractModule::NETWORK, new Network());
}

int		main()
{
	ModuleFactory	factory;

	initModules(factory);

	std::map<AbstractModule::Type, AbstractModule*> modules;
	modules = factory.getModules();
	while (42)
	{
		std::cout << "\033\143" << std::endl;
		for (std::map<AbstractModule::Type, AbstractModule*>::iterator itMap =
				modules.begin() ; itMap != modules.end() ; ++itMap)
		{
			itMap->second->updateData();
			std::vector<Info>	infos = itMap->second->getInfos();
			for (std::vector<Info>::iterator it = infos.begin() ;
					it != infos.end() ; ++it)
			{
				std::cout << it->getName() << ": ";
				std::cout << it->convert() << std::endl;
			}
			std::cout << std::endl;
		}
		std::cout << "============" << std::endl;
		sleep(1);
	}
	return 0;
}
