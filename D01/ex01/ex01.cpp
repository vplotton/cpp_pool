#include <string>
#include <iostream>

voidmemoryLeak()
{
	std::string	*panthere = new std::string("String panthere");

	std::cout << *panthere << std::endl;
	delete panthere;
}
