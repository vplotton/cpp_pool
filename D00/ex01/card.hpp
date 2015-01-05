/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   card.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 10:49:24 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/05 12:28:42 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARD_HPP
# define CARD_HPP


namespace std
{
	class Card
	{
		public:
			Card();
			~Card();
			void	add();
			void	printSearchShort();
			void	printSearchResult();
			boolean	isSet();

		private:
			boolean	m_set;
			string	m_firstName;
			string	m_lastName;
			string	m_nickName;
			string	m_login;
			string	m_postalAddress;
			string	m_emailAddress;
			string	m_phoneNumber;
			string	m_birthdayDate;
			string	m_favoriteMeal;
			string	m_underwearColor;
			string	m_darkestSecret;
	};
}

#endif /* !CARD_HPP */
