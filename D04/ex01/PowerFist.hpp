/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PowerFist.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:23:13 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 02:23:14 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POWERFIST_HPP
# define POWERFIST_HPP

#include "AWeapon.hpp"
#include <iostream>

class PowerFist : public AWeapon
{
	public:
		PowerFist();
		PowerFist(PowerFist const & src);
		~PowerFist();

		PowerFist & operator=(PowerFist const & rhs);

		virtual void	attack() const;

	private:

};

/*
std::ostream & operator<<(std::ostream & o, PowerFist const & i);
*/

#endif /* !POWERFIST_HPP */
