#include "Span.hpp"
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <stdexcept>

#define MAX	100000

int		main()
{
	Span sp = Span(5);
	sp.addNumber(5);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "Vector:\n" << sp << std::endl;
	std::cout << "Min: " << sp.shortestSpan() << std::endl;
	std::cout << "Max: " << sp.longestSpan() << std::endl;

	srand(time(NULL));
	std::vector<int>	filler(MAX);
	std::generate(filler.begin(), filler.end(), rand);


	int	last = 1;
	for (unsigned int i = 0 ; i < MAX ; ++i)
	{
		srand(time(NULL) * last);
		last = rand();
		filler.push_back((last % 3 == 0 ? -(last % MAX) : (last % MAX)));
	}
	/*
	   std::copy(filler.begin(), filler.end(),
	   		std::ostream_iterator<int>(std::cout, "\n"));
	   */
	Span	span(MAX);

	std::cout << std::endl << "[ empty ]" << std::endl;
	try
	{
		span.shortestSpan();
	}
	catch (std::runtime_error &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}


	span.addContainer(filler);

	std::cout << std::endl << "[ bigger array ] - " << MAX << " elements"  << std::endl;
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
