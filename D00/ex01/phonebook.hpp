/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 10:02:43 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/05 16:46:06 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "contact.hpp"

class PhoneBook
{
	public:
		PhoneBook();
		~PhoneBook();
		void	search();
		void	add();

	private:
		Contact m_contacts[8];
};

#endif /* !PHONEBOOK_HPP */
