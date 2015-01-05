#include "phonebook.hpp"
#include <iostream>

int		main()
{
	std::string commandLine;
	PhoneBook phoneBook;

	std::cout << "Available commands: ADD | SEARCH | EXIT" << std::endl;
	while (42)
	{
		std::cin >> commandLine;
		if (commandLine.compare("ADD") == 0)
		{
			phoneBook.add();
		}
		else if (commandLine.compare("SEARCH") == 0)
		{
			phoneBook.search();
		}
		else if (commandLine.compare("EXIT") == 0)
		{
			break ;
		}
		else
		{
			std::cout << "Wrong command.";
		}
	}
	return (0);
}
