/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:12:23 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/05 15:28:59 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
}

PhoneBook::~PhoneBook()
{
}

void	PhoneBook::add()
{
	bool allSet = true;
	
	for (int i = 0 ; i < 8 ; ++i)
	{
		if (m_contacts[i].isSet() == false)
		{
			allSet = false;
			m_contacts[i].add();
			break ;
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
		m_contacts[i].printSearchShort(i);
	}
	std::cout << "Choose an index to see full information: ";
	std::cin >> arg;
	if (arg >= 0 && arg < 8)
	{
		m_contacts[arg].printSearchResult();
	}
	else
	{
		std::cout << "Choice out of range." << std::endl;
	}
}
