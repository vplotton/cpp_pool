#include "phonebook.hpp"

int		main()
{
	std::string commandLine;
	PhoneBook phoneBook;

	while (42)
	{
		std::cin >> commandLine;
		if (commandLine.compare("ADD"))
		{
			phoneBook.add();
		}
		else if (commandLine.compare("SEARCH"))
		{
			phoneBook.search();
		}
		else if (commandLine.compare("EXIT"))
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
