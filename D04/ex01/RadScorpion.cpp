/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:23:19 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 02:59:55 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RadScorpion.hpp"

RadScorpion::RadScorpion() : Enemy(80, "RadScorpion")
{
	std::cout << "* click click click *" << std::endl;
}

RadScorpion::RadScorpion(RadScorpion const & src) : Enemy(80, "RadScorpion")
{
	*this = src;
}

RadScorpion::~RadScorpion()
{
	std::cout << "* SPROTCH *" << std::endl;
}

RadScorpion & RadScorpion::operator=(RadScorpion const & rhs)
{
	if (this != &rhs)
	{
		setHP(rhs.getHP());
		setType(rhs.getType());
	}
	return (*this);
}

void		RadScorpion::takeDamage(int damage)
{
	int	hpLeft = getHP() - damage;

	if (damage > 0)
	{
		setHP((hpLeft > 0 ? hpLeft : 0));
	}
}

std::ostream & operator<<(std::ostream & o, RadScorpion const & i)
{
	o << "Enemy [ " << i.getType() << " ]: " << i.getHP() << "HP." << std::endl;
	return (o);
}
