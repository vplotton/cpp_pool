#include "Fixed.hpp"
#include <cmath>


Fixed::Fixed() : m_rawBits(0), m_nbFracBits(8)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const numInt) : m_nbFracBits(8)
{
	std::cout << "Int constructor called" << std::endl;
	m_rawBits = numInt * std::pow(2, m_nbFracBits);
}

Fixed::Fixed(float const numFloat): m_nbFracBits(8)
{
	std::cout << "Float constructor called" << std::endl;
	m_rawBits = roundf(numFloat * std::pow(2, m_nbFracBits));
}

Fixed::Fixed(Fixed const & src) : m_rawBits(0), m_nbFracBits(8)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &	Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		m_rawBits = rhs.getRawBits();
	}
	return (*this);
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
	std::cout << "setRawBits member function called" << std::endl;
	m_rawBits = raw;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_rawBits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & src)
{
	o << src.toFloat();
	return (o);
}
