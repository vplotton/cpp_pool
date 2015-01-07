#include "Fixed.hpp"

Fixed::Fixed() : m_fixedPoint(0), m_fracBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) : m_fixedPoint(0), m_fracBits(0)
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
		/* my implementation, don't forget to change this. */
	}
	return (*this);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	if (raw > -1 && raw < 8)
	{
		m_fixedPoint = raw;
	}
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (m_fracBits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & i)
{
	o << i.getRawBits();
	return (o);
}
