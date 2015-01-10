/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 02:22:45 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/10 03:04:40 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

#include <iostream>
#include <string>

class Enemy
{
	public:
		Enemy();
		Enemy(int hp, std::string const & type);
		Enemy(Enemy const & src);
		virtual	~Enemy();

		Enemy & operator=(Enemy const & rhs);
		
		int		getHP() const;
		std::string	getType() const;
		void		setHP(int hitPoints);
		void		setType(std::string const & type);

		virtual void	takeDamage(int) = 0;

	private:
		std::string	m_type;
		int		m_hitPoints;

};

std::ostream & operator<<(std::ostream & o, Enemy const & i);

#endif /* !ENEMY_HPP */
