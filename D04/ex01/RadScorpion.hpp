/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RadScorpion.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:23:26 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 03:00:04 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADSCORPION_HPP
# define RADSCORPION_HPP

#include "Enemy.hpp"
#include <iostream>

class RadScorpion : public Enemy
{
	public:
		RadScorpion();
		RadScorpion(RadScorpion const & src);
		~RadScorpion();

		RadScorpion & operator=(RadScorpion const & rhs);

		virtual void    takeDamage(int);

	private:

};

std::ostream & operator<<(std::ostream & o, RadScorpion const & i);

#endif /* !RADSCORPION_HPP */
