#include <iostream>
#include <sys/utsname.h>

struct utsname unameData;

int		main()
{
	std::cout << "Welcome to GKrellM" << std::endl;
#if defined(__APPLE__) && defined(__MACH__)
	std::cout << "MAX OS X" << std::endl;
#endif

	uname(&unameData);

	std::cout << "Sysname: " << unameData.sysname << std::endl;
	std::cout << "Nodename: " << unameData.nodename << std::endl;
	std::cout << "Release: " << unameData.release << std::endl;
	std::cout << "Version: " << unameData.version << std::endl;
	std::cout << "Machine: " << unameData.machine << std::endl;

	return 0;
}
