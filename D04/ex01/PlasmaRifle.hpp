/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlasmaRifle.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:22:59 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 02:57:50 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMARIFLE_HPP
# define PLASMARIFLE_HPP

#include "AWeapon.hpp"
#include <iostream>

class PlasmaRifle : public AWeapon
{
	public:
		PlasmaRifle();
		PlasmaRifle(PlasmaRifle const & src);
		~PlasmaRifle();

		PlasmaRifle & operator=(PlasmaRifle const & rhs);

		virtual	void	attack() const;

	private:

};

std::ostream & operator<<(std::ostream & o, PlasmaRifle const & i);

#endif /* !PLASMARIFLE_HPP */
