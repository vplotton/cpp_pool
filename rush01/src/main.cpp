#include "SysInfo.hpp"
#include <unistd.h>
#include <iostream>

int		main()
{
	SysInfo	sysInfo;

	std::cout << "Sysname: " << sysInfo.getSysName() << std::endl;
	std::cout << "Nodename: " << sysInfo.getNodeName() << std::endl;
	std::cout << "Release: " << sysInfo.getRelease() << std::endl;
	std::cout << "Version: " << sysInfo.getVersion() << std::endl;
	std::cout << "Machine: " << sysInfo.getMachine() << std::endl;

	return 0;
}
