#include "Scalar.hpp"
#include <iostream>
#include <cstdlib>

int main(int argc, char const **argv)
{
	double test;
	char * end;

	if (argc != 2)
	{
		std::cout << "Wrong input" << std::endl;
		return -1;
	}
	test = strtod(argv[1], &end);
	if (test == 0 && end == argv[1])
	{
		Scalar value1 = Scalar(argv[1][0]);
		std::cout << value1 << std::endl;
	}
	else
	{
		Scalar value1 = Scalar(test);
		std::cout << value1 << std::endl;
	}
	return 0;
}

