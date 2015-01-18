#include "modules/RamFree.hpp"
#include <unistd.h>
#include <iostream>

int		main()
{
	RamFree	ramFree;

	ramFree.initData();

	std::cout << "Total amount: " << ramFree.retrieveTotalAmount() << std::endl;
	int count = 0;
	while (++count < 70)
	{
		ramFree.updateData();

		std::cout << "Percentage: "
			<< ramFree.retrievePercentage() << std::endl;
		std::cout << "Current amount: "
			<< ramFree.retrieveCurrentAmount() << std::endl;
		std::cout << "Final result: "
			<< ramFree.convertToReadable() << std::endl;
		sleep(1);
	}
	return 0;
}
