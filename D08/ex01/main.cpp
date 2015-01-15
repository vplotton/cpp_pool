#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <stdexcept>

#define MAX	10000

int		main()
{
	std::vector<int>	filler;

	int	last = 1;
	for (unsigned int i = 0 ; i < MAX ; ++i)
	{
		srand(time(NULL) * last);
		last = rand();
		filler.push_back((last % 3 == 0 ? -(last % MAX) : (last % MAX)));
	}

	std::copy(filler.begin(), filler.end(),
			std::ostream_iterator<int>(std::cout, "\n"));

	Span	span(MAX / 10);
	span.addContainer(filler);

	try
	{
		span.addNumber(4);
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	std::cout << "Min: " << span.shortestSpan() << std::endl;
	std::cout << "Max: " << span.longestSpan() << std::endl;
	return 0;
}
