#include "Span.hpp"
#include <cstdlib>
#include <stdexcept>

Span::Span()
{
}

Span::Span(unsigned int const & size) : m_sizeMax(size)
{
}

Span::Span(Span const & src)
{
	*this = src;
}

Span::~Span()
{
}

Span & Span::operator=(Span const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

std::vector<int>	Span::getStore() const
{
	return m_store;
}

void	Span::addContainer(std::vector<int> & filler)
{
	unsigned int count = 0;
	for (std::vector<int>::iterator it = filler.begin() ; it != filler.end() ; ++it)
	{
		if (count == m_sizeMax)
		{
			break ;
		}
		m_store.push_back(*it);
		++count;
	}
}

void	Span::addNumber(int const & number)
{
	if (m_sizeMax >= m_store.size())
	{
		throw (std::runtime_error("Span::CannotStoreMoreElements"));
	}
	else
	{
		m_store.push_back(number);
	}
}

unsigned int	Span::shortestSpan()
{
	unsigned int	diff;
	unsigned int	minSpan = -1;
	int		previous;

	for (std::vector<int>::iterator it = m_store.begin() ; it != m_store.end() ; ++it)
	{
		if (it != m_store.begin())
		{
			diff = std::abs(*it - previous);
			if (diff < minSpan)
			{
				minSpan = diff;
			}
		}
		previous = *it;
	}
	return minSpan;
}

unsigned int	Span::longestSpan()
{
	unsigned int    diff;
	unsigned int    maxSpan = 0;
	int             previous;

	for (std::vector<int>::iterator it = m_store.begin() ; it != m_store.end() ; ++it)
	{   
		if (it != m_store.begin())
		{   
			diff = std::abs(*it - previous);
			if (diff > maxSpan)
			{
				maxSpan = diff;
			}   
		}   
		previous = *it;
	}   
	return maxSpan;
}

std::ostream & operator<<(std::ostream & o, Span const & i)
{
	std::vector<int>	store = i.getStore();
	for (std::vector<int>::const_iterator it = store.begin() ; it != store.end() ; ++it)
	{
		o << *it << std::endl;
	}
	return (o);
}
