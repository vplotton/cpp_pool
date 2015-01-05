/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 15:27:45 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/05 15:29:44 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "contact.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact()
{
	m_set = false;
}

Contact::~Contact()
{
}

void	getFieldStream(std::string &field, std::string fieldName)
{
	std::cout << "- " << fieldName << ": ";
	std::cin >> field;
}

void	Contact::add()
{
	m_set = true;
	std::cout << "Please fill the following info:" << std::endl;
	getFieldStream(m_firstName, "first name");
	getFieldStream(m_lastName, "last name");
	getFieldStream(m_nickName, "nick name");
	getFieldStream(m_login, "login");
	getFieldStream(m_postalAddress, "postal address");
	getFieldStream(m_emailAddress, "email address");
	getFieldStream(m_phoneNumber, "phone number");
	getFieldStream(m_birthdayDate, "birthday date");
	getFieldStream(m_favoriteMeal, "favorite meal");
	getFieldStream(m_underwearColor, "underwear color");
	getFieldStream(m_darkestSecret, "darkest secret");
}

void	printStringShort(std::string field)
{
	std::cout << "|";
	if (field.size() > 10)
	{
		std::cout << field.substr(0, 9) << ".";
	}
	else
	{
		std::cout << std::left << std::setw(10) << field;
	}
}

void	Contact::printSearchShort(int i)
{
	if (m_set == false)
	{
		return ;
	}
	std::cout << std::left << std::setw(10) << i;
	printStringShort(m_firstName);
	printStringShort(m_lastName);
	printStringShort(m_nickName);
	std::cout << std::endl;
}

void	printResultLine(std::string field)
{
	std::cout << field << std::endl;
}

void	Contact::printSearchResult()
{
	if (m_set == false)
	{
		std::cout << "No data." << std::endl;
		return ;
	}
	printResultLine(m_firstName);
	printResultLine(m_lastName);
	printResultLine(m_nickName);
	printResultLine(m_login);
	printResultLine(m_postalAddress);
	printResultLine(m_emailAddress);
	printResultLine(m_phoneNumber);
	printResultLine(m_birthdayDate);
	printResultLine(m_favoriteMeal);
	printResultLine(m_underwearColor);
	printResultLine(m_darkestSecret);
}

bool	Contact::isSet()
{
	return (m_set);
}
