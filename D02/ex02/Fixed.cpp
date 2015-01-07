/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 19:58:25 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/07 20:34:11 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>


Fixed::Fixed() : m_rawBits(0), m_nbFracBits(8)
{
}

Fixed::Fixed(int const numInt) : m_nbFracBits(8)
{
	m_rawBits = numInt * std::pow(2, m_nbFracBits);
}

Fixed::Fixed(float const numFloat): m_nbFracBits(8)
{
	m_rawBits = roundf(numFloat * std::pow(2, m_nbFracBits));
}

Fixed::Fixed(Fixed const & src) : m_rawBits(0), m_nbFracBits(8)
{
	*this = src;
}

Fixed::~Fixed()
{
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	if (this != &rhs)
	{
		m_rawBits = rhs.getRawBits();
	}
	return (*this);
}

Fixed		&Fixed::operator++()
{
	m_rawBits++;
	return (*this);
}

Fixed		Fixed::operator++(int)
{
	Fixed	tmp(*this);

	operator++();
	return (tmp);
}

Fixed		&Fixed::operator--()
{
	m_rawBits--;
	return (*this);
}

Fixed       Fixed::operator--(int)
{
	Fixed   tmp(*this);
	
	operator--();
	return (tmp);
}

Fixed	 Fixed::operator+(Fixed const & rhs)
{
	return (Fixed(toFloat() + rhs.toFloat()));
}

Fixed	 Fixed::operator-(Fixed const & rhs)
{
	return (Fixed(toFloat() - rhs.toFloat()));
}

Fixed	 Fixed::operator*(Fixed const & rhs)
{
	return (Fixed(toFloat() * rhs.toFloat()));
}

Fixed	Fixed::operator/(Fixed const & rhs)
{
	return (Fixed(toFloat() / rhs.toFloat()));
}

bool	Fixed::operator<(Fixed const & rhs) const
{
	return ((m_rawBits < rhs.getRawBits() ? true : false));
}

bool	Fixed::operator>(Fixed const & rhs) const
{
	return ((m_rawBits > rhs.getRawBits() ? true : false));
}

bool	Fixed::operator<=(Fixed const & rhs) const
{
	return ((m_rawBits <= rhs.getRawBits() ? true : false));
}

bool	Fixed::operator>=(Fixed const & rhs) const
{
	return ((m_rawBits >= rhs.getRawBits() ? true : false));
}

bool	Fixed::operator==(Fixed const & rhs) const
{
	return ((m_rawBits == rhs.getRawBits() ? true : false));
}

bool	Fixed::operator!=(Fixed const & rhs) const
{
	return ((m_rawBits != rhs.getRawBits() ? true : false));
}

Fixed const	&Fixed::min(Fixed const &left, Fixed const &right)
{
	return ((left < right ? left : right));
}

Fixed const	&Fixed::max(Fixed const &left, Fixed const &right)
{
	return ((left >= right ? left : right));
}

Fixed	&Fixed::min(Fixed &left, Fixed &right)
{
	return ((left < right ? left : right));
}

Fixed	&Fixed::max(Fixed &left, Fixed &right)
{
	return ((left >= right ? left : right));
}

int		Fixed::toInt(void) const
{
	return ((int)(m_rawBits / std::pow(2, m_nbFracBits)));
}


float	Fixed::toFloat(void) const
{
	return (m_rawBits / std::pow(2, m_nbFracBits));
}

void	Fixed::setRawBits(int const raw)
{
	m_rawBits = raw;
}

int	Fixed::getRawBits() const
{
	return (m_rawBits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
	o << src.toFloat();
	return (o);
}
