#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(Fixed const & src);
		~Fixed();

		Fixed & operator=(Fixed const & rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int			m_rawBits;
		int const 	m_nbFracBits;

};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif /* !FIXED_HPP */
