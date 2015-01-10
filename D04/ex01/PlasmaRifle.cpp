/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:22:53 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 03:05:15 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle() : AWeapon("Plasma Rifle" , 21, 5)
{
}

PlasmaRifle::PlasmaRifle(PlasmaRifle const & src) : AWeapon("Plasma Rifle" , 21, 5)
{
	*this = src;
}

PlasmaRifle::~PlasmaRifle()
{
}

PlasmaRifle & PlasmaRifle::operator=(PlasmaRifle const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

void	PlasmaRifle::attack() const
{
	std::cout << "* piouuu piouuu piouuu *" << std::endl;
}


std::ostream & operator<<(std::ostream & o, PlasmaRifle const & i)
{
	o << "Weapon [ " << i.getName() << " ]: "
		<< i.getDamage() << "damage, costs " << i.getAPCost() << "AP" << std::endl;
	return (o);
}

