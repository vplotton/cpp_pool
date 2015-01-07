#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const & src);
		~Fixed();

		Fixed & operator=(Fixed const & rhs);

		int	toInt(void) const;
		float	toFloat(void) const;
		int	getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int		m_fixedPoint;
		int const 	m_fracBits = 1 << 8;

};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif /* !FIXED_HPP */
