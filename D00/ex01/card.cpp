#include "card.hpp"

Card::Card()
{
	m_set = false;
}

Card::~Card()
{
}

void	getFieldStream(std::string &field, std::string fieldName)
{
	std::cout << "- " << fieldName << ": ";
	std::cin >> field;
}

void	Card::add()
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

void	printStringShort(string field)
{
	std::cout << "|";
	if (field.size() > 10)
	{
		std::cout << field.resize(9) << ".";
	}
	else
	{
		std::cout << field;
		if (field.size() < 10)
		{
			for (int i = 0 ; i < (10 - field.size()) ; ++i)
			{
				std::cout << " ";
			}
		}
	}
}

void	Card::printSearchShort(int i)
{
	std::cout << i;
	std::cout << "         ";
	printStringShort(m_firstName);
	printStringShort(m_lastName);
	printStringShort(m_nickName);
	std::endl;
}

void	printResultLine(std::string field)
{
	std::cout << field << std::endl;
}

void	Card::printSearchResult()
{
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

boolean	Card::isSet()
{
	return (m_set);
}
