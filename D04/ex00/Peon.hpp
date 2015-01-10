/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Peon.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:19:18 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 02:19:19 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PEON_HPP
# define PEON_HPP

#include "Victim.hpp"
#include <iostream>
#include <string>

class Peon : public Victim
{
	public:
		Peon(std::string name);
		Peon(Peon const & src);
		~Peon();

		Peon & operator=(Peon const & rhs);

		virtual void	getPolymorphed() const;

	private:
		Peon();

};

/*
std::ostream & operator<<(std::ostream & o, Peon const & rhs);
*/

#endif /* !PEON_HPP */
