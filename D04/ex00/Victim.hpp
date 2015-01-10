/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Victim.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:19:41 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 03:13:13 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VICTIM_HPP
# define VICTIM_HPP

#include <iostream>
#include <string>

class Victim
{
	public:
		Victim(std::string name);
		Victim(Victim const & src);
		virtual ~Victim();

		Victim & operator=(Victim const & rhs);

		void		setName(std::string const name);
		std::string	getName() const;

		virtual void	getPolymorphed() const;
		void		introduceHimself() const;

	protected:
		Victim();
		std::string m_name;

};

std::ostream & operator<<(std::ostream & o, Victim const & rhs);

#endif /* !VICTIM_HPP */
