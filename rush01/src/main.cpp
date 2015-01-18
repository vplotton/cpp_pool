#include "modules/SwapMemory.hpp"
#include <unistd.h>
#include <iostream>

int		main()
{
	SwapMemory	swapMemory;

	swapMemory.initData();

	std::cout << "Total amount: " << swapMemory.retrieveTotalAmount() << std::endl;
	int count = 0;
	while (++count < 70)
	{
		swapMemory.updateData();

		std::cout << "Percentage: "
			<< swapMemory.retrievePercentage() << std::endl;
		std::cout << "Current amount: "
			<< swapMemory.retrieveCurrentAmount() << std::endl;
		std::cout << "Final result: "
			<< swapMemory.convertToReadable() << std::endl;
		sleep(1);
	}
	return 0;
}
