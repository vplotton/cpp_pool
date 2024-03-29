#include "Fixed.hpp"

Fixed::Fixed() : m_rawBits(0), m_nbFracBits(8)
{
	std::cout << "Default constructor called" << std::endl;
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

Fixed & Fixed::operator=(Fixed const & rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	if (this != &rhs)
	{
		m_rawBits = rhs.getRawBits();
	}
	return (*this);
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

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.getRawBits();
	return (o);
}
