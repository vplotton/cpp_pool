/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:19:30 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 02:19:32 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORCERER_HPP
# define SORCERER_HPP

#include "Victim.hpp"
#include "Peon.hpp"
#include <iostream>
#include <string>

class Sorcerer
{
	public:
		Sorcerer(std::string name, std::string title);
		Sorcerer(Sorcerer const & src);
		~Sorcerer();

		Sorcerer & operator=(Sorcerer const & rhs);

		std::string	getName() const;
		std::string	getTitle() const;
		void		setName(std::string const name);
		void		setTitle(std::string const title);

		void	introduceHimself() const;
		void	polymorph(Victim const & victim);
		void	polymorph(Peon const & victim);

	private:
		Sorcerer();
		std::string m_name;
		std::string m_title;

};

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs);

#endif /* !SORCERER_HPP */
