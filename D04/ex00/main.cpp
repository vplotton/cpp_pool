/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:21:24 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 02:21:26 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sorcerer.hpp"
#include "Victim.hpp"
#include "Peon.hpp"

int	main()
{
	std::string tests[8] =
	{
		"sorcerer", "sorcererModif",
		"sorcererTitle", "sorcererTitleModif",
		"Victim", "VictimModif",
		"Peon", "PeonModif",
	};

	std::cout << "=============================" << std::endl;
	std::cout << "test [ - should be -]: result" << std::endl;
	std::cout << std::endl;

	std::cout << "=== Sorcerer ===" << std::endl;
	Sorcerer *sorcerer = new Sorcerer(tests[0], tests[2]);

	std::cout << "test ostream: " << *sorcerer << std::endl;

	std::cout << "test [ " << tests[0] << " ]: " << sorcerer->getName() << std::endl;
	std::cout << "test [ " << tests[2] << " ]: " << sorcerer->getTitle() << std::endl;

	sorcerer->setName(tests[1]);
	sorcerer->setTitle(tests[3]);
	std::cout << "test [ " << tests[1] << " ]: " << sorcerer->getName() << std::endl;
	std::cout << "test [ " << tests[3] << " ]: " << sorcerer->getTitle() << std::endl;

	delete sorcerer;

	std::cout << std::endl;

	std::cout << "=== Victim ===" << std::endl;
	Victim  *victim = new Victim(tests[4]);

	std::cout << "test ostream: " << *victim << std::endl;

	std::cout << "test [ " << tests[4] << " ]: " << victim->getName() << std::endl;
	victim->setName(tests[5]);
	std::cout << "test [ " << tests[5] << " ]: " << victim->getName() << std::endl;

	delete victim;

	std::cout << std::endl;
	std::cout << "=== Peon ===" << std::endl;
	Peon  *peon = new Peon(tests[6]);

	std::cout << "test ostream: " << *victim << std::endl;

	std::cout << "test [ " << tests[6] << " ]: " << peon->getName() << std::endl;
	peon->setName(tests[7]);
	std::cout << "test [ " << tests[7] << " ]: " << peon->getName() << std::endl;

	delete peon;

	std::cout << std::endl << std::endl;

	Sorcerer robert("Robert","the Magnificent");
	Victim jim("Jimmy");
	Peon joe("Joe");
	std::cout << robert << jim << joe;
	robert.polymorph(jim);
	robert.polymorph(joe);


	return 0;
}
