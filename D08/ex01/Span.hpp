#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span
{
	public:
		Span(unsigned int const &);
		Span(Span const & src);
		Span & operator=(Span const & rhs);
		~Span();

		std::vector<int>	getStore() const;

		void    addContainer(std::vector<int> &);
		void	addNumber(int const &);
		unsigned int	shortestSpan();
		unsigned int	longestSpan();

	private:
		unsigned int		m_sizeMax;
		std::vector<int>	m_store;

		Span();

};

std::ostream & operator<<(std::ostream & o, Span const & i);

#endif /* !SPAN_HPP */
