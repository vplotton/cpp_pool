#include "Info.hpp"
#include <iostream>

int		main()
{
	Info<unsigned long long>	info("name", EInfo::BYTES);

	info.setInfo(1230123);

	std::cout << info.getName() << std::endl;
	std::cout << info.getInfo() << std::endl;
	std::cout << info.convert(info.getInfo()) << std::endl;

	return 0;
}
