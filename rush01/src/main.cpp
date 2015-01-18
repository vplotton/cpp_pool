#include "modules/Cpu.hpp"
#include "modules/Memory.hpp"

#include <iostream>
#include <vector>
#include <map>
#include <unistd.h>

int		main()
{
	std::map<AbstractModule::Type, AbstractModule*>	myApps;


	myApps.insert(
			std::make_pair<AbstractModule::Type, AbstractModule*>(
				AbstractModule::CPU, new Cpu()));

	myApps.insert(
			std::make_pair<AbstractModule::Type, AbstractModule*>(
				AbstractModule::MEMORY, new Memory()));

	myApps.at(AbstractModule::CPU)->initData();
	myApps.at(AbstractModule::MEMORY)->initData();
	int		count = 0;

	while (++count < 70)
	{
		for (std::map<AbstractModule::Type, AbstractModule*>::iterator itMap =
				myApps.begin() ; itMap != myApps.end() ; ++itMap)
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
