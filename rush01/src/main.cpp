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
#include <unistd.h>
#include <iostream>
#include <string>
#include <ncurses.h>
#include "Display.hpp"
#include <list>
#include "Box.hpp"


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
	int ch;
	int i = 1;
	initscr();          /* Start curses mode        */
	raw();
	noecho();
	keypad(stdscr, TRUE);       /* I need that nifty F1     */
	noecho();
	curs_set(0);                // desactive le curseur
	nodelay(stdscr, TRUE);      //desactive l attente dune touche pour continuer
	init_pair(1, COLOR_CYAN, COLOR_BLACK);

	Display *d = new Display();

	std::map<AbstractModule::Type, AbstractModule*> modules;
	modules = factory.getModules();

	d->fill_pos();	
//	d->makeBox();
	erase();

	while((ch = getch()) != KEY_F(1))
	{
		d->makeBox();
			for (std::map<AbstractModule::Type, AbstractModule*>::iterator itMap =	modules.begin() ; itMap != modules.end() ; ++itMap)
		{
			if(d->getCheck(itMap->first) == false)
			{
			itMap->second->updateData();
			std::vector<Info>	infos = itMap->second->getInfos();
			for (std::vector<Info>::iterator it = infos.begin() ;
					it != infos.end() ; ++it)
			{
				d->fillBox(itMap->first, it, i, itMap->second->getModuleName());
			  i = 	i + 2;
			  Display::begin = 1;
			}
			i = 1;
			}
			Display::begin = 0;
		}
		//std::cout << "============" << std::endl;
		d->printBox();
		sleep(1);
		for(int j = 0; j < 10; j++)
		{
			if (d->getCheck(j) == false)
				d->destroy_win(d->getWindows(j)->getWinBox());
		}
	
		Box::startX = 0;
		Box::startY = 0;
		Box::totalLen = 0;
		i = 1;
	}
	endwin();
	return 0;
}
