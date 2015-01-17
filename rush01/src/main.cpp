#include "modules/CpuLoad.hpp"
#include <unistd.h>
#include <iostream>

int		main()
{
	CpuLoad	cpuLoad;

	cpuLoad.initData();

	std::cout << "Total amount: " << cpuLoad.retrieveTotalAmount() << std::endl;
	int count = 0;
	while (++count < 70)
	{
		cpuLoad.updateData();

		std::cout << "Percentage: " << cpuLoad.retrievePercentage() << std::endl;
		std::cout << "Current amount: " << cpuLoad.retrieveCurrentAmount() << std::endl;
		std::cout << "Final result: " << cpuLoad.convertToReadable() << std::endl;
		sleep(1);
	}
	return 0;
}
