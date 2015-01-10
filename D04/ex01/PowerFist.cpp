/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:23:06 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 03:01:34 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PowerFist.hpp"

PowerFist::PowerFist() : AWeapon("Power Fist", 50, 8)
{
}

PowerFist::PowerFist(PowerFist const & src) : AWeapon("Power Fist", 50, 8)
{
	*this = src;
}

PowerFist::~PowerFist()
{
}

PowerFist & PowerFist::operator=(PowerFist const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

void	PowerFist::attack() const
{
	std::cout << "* pschhh... SBAM! *" << std::endl;
}


std::ostream & operator<<(std::ostream & o, PowerFist const & i)
{
	o << "Weapon [ Power Fist ]: "
		<< i.getDamage() << "damage, costs " << i.getAPCost() << "AP" << std::endl;
	return (o);
}

