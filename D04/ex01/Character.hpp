/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:22:35 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 02:22:36 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include "AWeapon.hpp"
#include "Enemy.hpp"
#include <iostream>
#include <string>

class Character
{
	public:
		Character();
		Character(std::string name);
		Character(Character const & src);
		~Character();

		Character & operator=(Character const & rhs);

		void		recoverAP();
		void		equip(AWeapon*);
		void		attack(Enemy* &enemy);
		std::string const	&getName() const;
		AWeapon				*getWeapon() const;
		int					getAP() const;

	private:
		std::string	m_name;
		int		m_actionPoints;
		AWeapon		*m_weapon;

};

std::ostream & operator<<(std::ostream & o, Character const & i);

#endif /* !CHARACTER_HPP */
