#include "phonebook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	std::cout << "patate" << std::endl;
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add()
{
	bool allSet = true;
	
	for (int i = 0 ; i < 8 ; ++i)
	{
		if (m_cards[i].isSet() == false)
		{
			allSet = false;
			m_cards[i].add();
		}
	}
	if (allSet == true)
	{
		std::cout << "Your phonebook is full." << std::endl;
	}
}

void	PhoneBook::search()
{
	int		arg;

	std::cout << "index     |first name|last name |nickname" << std::endl;
	for (int i = 0 ; i < 8 ; ++i)
	{
		m_cards[i].printSearchShort();
	}
	std::cout << "Choose an index to see full information: ";
	std::cin >> arg;
	if (0 <= arg < 8)
	{
		m_cards[arg].printSearchResult();
	}
	else
	{
		std::cout << "Wrong choice." << std::endl;
	}
}
