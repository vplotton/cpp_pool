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

		int		toInt(void) const;
		float	toFloat(void) const;
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int			m_rawBits;
		int const 	m_nbFracBits;

};

std::ostream & operator<<(std::ostream & o, Fixed const & src);

#endif /* !FIXED_HPP */
