#include <string>
#include <iostream>

void	printPtr(std::string const *ptr)
{
	std::cout << *ptr << std::endl;
}

void	printRef(std::string const &ref)
{
	std::cout << ref << std::endl;
}

int	main()
{
	std::string myString("HI THIS IS BRAIN");

	std::string *stringPtr = &myString;
	std::string &stringRef = myString;

	printPtr(stringPtr);
	printRef(stringRef);

	return (0);
}
