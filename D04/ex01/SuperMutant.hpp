/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SuperMutant.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:23:36 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 02:59:35 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SUPERMUTANT_HPP
# define SUPERMUTANT_HPP

#include "Enemy.hpp"
#include <iostream>

class SuperMutant : public Enemy
{
	public:
		SuperMutant();
		SuperMutant(SuperMutant const & src);
		~SuperMutant();

		SuperMutant & operator=(SuperMutant const & rhs);

		virtual void    takeDamage(int);

	private:

};

std::ostream & operator<<(std::ostream & o, SuperMutant const & i);

#endif /* !SUPERMUTANT_HPP */
