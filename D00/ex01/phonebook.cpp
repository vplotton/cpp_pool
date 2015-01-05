/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 13:12:23 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/05 13:41:18 by vplotton         ###   ########.fr       */
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
		if (m_cards[i].isSet() == false)
		{
			allSet = false;
			m_cards[i].add();
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
		m_cards[i].printSearchShort(i);
	}
	std::cout << "Choose an index to see full information: ";
	std::cin >> arg;
	if (arg >= 0 && arg < 8)
	{
		m_cards[arg].printSearchResult();
	}
	else
	{
		std::cout << "Choice out of range." << std::endl;
	}
}
