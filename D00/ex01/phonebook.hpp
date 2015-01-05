/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 10:02:43 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/05 13:02:09 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	search();
		void	add();

	private:
		Card m_cards[8];
};

#endif /* !PHONEBOOK_HPP */
