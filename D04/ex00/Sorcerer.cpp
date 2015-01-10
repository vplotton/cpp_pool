/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sorcerer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:19:23 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 02:19:26 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"

Sorcerer::Sorcerer() : m_name(""), m_title("")
{
}

Sorcerer::Sorcerer(std::string name, std::string title) : m_name(name), m_title(title)
{
	std::cout << name << ", " << title << ", is born !" << std::endl;
}

Sorcerer::Sorcerer(Sorcerer const & src)
{
	*this = src;
}

Sorcerer::~Sorcerer()
{
	std::cout << m_name << ", " << m_title << ", is dead. Consequences will never be the same !" << std::endl;
}

Sorcerer & Sorcerer::operator=(Sorcerer const & rhs)
{
	if (this != &rhs)
	{
		m_name = rhs.m_name;
		m_title = rhs.m_title;
	}
	return (*this);
}

void	Sorcerer::setName(std::string const name)
{
	m_name = name;
}

void	Sorcerer::setTitle(std::string const title)
{
	m_title = title;
}

std::string	Sorcerer::getName() const
{
	return m_name;
}

std::string	Sorcerer::getTitle() const
{
	return m_title;
}

void	Sorcerer::introduceHimself() const
{
	std::cout << "I am" << m_name << ", " << m_title << ", and I like ponies !" << std::endl;
}

void	Sorcerer::polymorph(Victim const & victim)
{
	victim.getPolymorphed();
}

void	Sorcerer::polymorph(Peon const & victim)
{
	victim.getPolymorphed();
}

std::ostream & operator<<(std::ostream & o, Sorcerer const & rhs)
{
	o << "I am " << rhs.getName() << ", " << rhs.getTitle() << ", and I like ponies !" << std::endl;
	return (o);
}
