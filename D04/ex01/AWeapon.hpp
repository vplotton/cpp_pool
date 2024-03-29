/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AWeapon.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:22:11 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 03:04:04 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AWEAPON_HPP
# define AWEAPON_HPP

#include <iostream>
#include <string>

class AWeapon
{
	public:
		AWeapon();
		AWeapon(std::string const & name, int apcost, int damage);
		AWeapon(AWeapon const & src);
		virtual	~AWeapon();

		AWeapon & operator=(AWeapon const & rhs);

		std::string	getName() const;
		int		getAPCost() const;
		int		getDamage() const;
		
		virtual void	attack() const = 0;

	private:
		std::string	m_name;
		int		m_actionPoints;
		int		m_attackDamage;

};

std::ostream & operator<<(std::ostream & o, AWeapon const & i);

#endif /* !AWEAPON_HPP */
