/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   card.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 10:49:24 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/05 13:41:13 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARD_HPP
# define CARD_HPP

#include <string>

class Card
{
	public:
		Card();
		~Card();
		void	add();
		void	printSearchShort(int i);
		void	printSearchResult();
		bool	isSet();

	private:
		bool	m_set;
		std::string	m_firstName;
		std::string	m_lastName;
		std::string	m_nickName;
		std::string	m_login;
		std::string	m_postalAddress;
		std::string	m_emailAddress;
		std::string	m_phoneNumber;
		std::string	m_birthdayDate;
		std::string	m_favoriteMeal;
		std::string	m_underwearColor;
		std::string	m_darkestSecret;
};

#endif /* !CARD_HPP */
