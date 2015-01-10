/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:22:40 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 03:04:35 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.hpp"

Enemy::Enemy() : m_type(""), m_hitPoints(0)
{
}

Enemy::Enemy(int hp, std::string const & type) : m_type(type), m_hitPoints(hp)
{
}

Enemy::Enemy(Enemy const & src)
{
	*this = src;
}

Enemy::~Enemy()
{
}

Enemy & Enemy::operator=(Enemy const & rhs)
{
	if (this != &rhs)
	{
		m_hitPoints = rhs.m_hitPoints;
		m_type = rhs.m_type;
	}
	return (*this);
}

std::string	Enemy::getType() const
{
	return m_type;
}

int		Enemy::getHP() const
{
	return m_hitPoints;
}

void		Enemy::setType(std::string const & type)
{
	m_type = type;
}

void		Enemy::setHP(int hitPoints)
{
	m_hitPoints = hitPoints;
}

std::ostream & operator<<(std::ostream & o, Enemy const & i)
{
	o << "Enemy [ " << i.getType() << " ]: " << i.getHP() << "HP." << std::endl;
	return (o);
}
