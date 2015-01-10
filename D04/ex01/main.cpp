/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:23:40 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 03:07:11 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PlasmaRifle.hpp"
#include "SuperMutant.hpp"
#include "RadScorpion.hpp"
#include "PowerFist.hpp"
#include "Character.hpp"

int main()
{
	Character* zaz = new Character("zaz");
	std::cout << *zaz;
	Enemy* b = new RadScorpion();
	Enemy* c = new SuperMutant();
	std::cout << *b;
	std::cout << *c;
	std::cout << std::endl;

	AWeapon* pr = new PlasmaRifle();
	AWeapon* pf = new PowerFist();
	std::cout << *pr;
	std::cout << *pf;
	std::cout << std::endl;
	
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->equip(pf);
	zaz->attack(b);
	std::cout << *zaz;
	zaz->equip(pr);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;
	zaz->attack(b);
	std::cout << *zaz;

	std::cout << std::endl;
	std::cout << std::endl;
	if (b == NULL)
	{
		std::cout << "enemy is NULL" << std::endl;
	}
	else
	{
		std::cout << "enemy is not NULL" << std::endl;
	}

	while (b && b->getHP())
	{
		zaz->attack(b);
		zaz->recoverAP();
		zaz->recoverAP();
	}
	
	if (b == NULL)
	{
		std::cout << "enemy is NULL" << std::endl;
	}
	else
	{
		std::cout << "enemy is not NULL" << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	zaz->recoverAP();
	std::cout << *zaz;
	zaz->equip(pf);
	std::cout << *zaz;
	zaz->attack(c);
	zaz->equip(pr);
	std::cout << *zaz;
	while (c && c->getHP())
	{
		zaz->attack(c);
		zaz->recoverAP();
		zaz->recoverAP();
	}


	return 0;
}
