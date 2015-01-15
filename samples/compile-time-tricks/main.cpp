#include "CTAssert.hpp"
#include <iostream>

int		main()
{
/*	CTAssert<(sizeof(int*) < sizeof(int))>();*/ // will not compile
	CTAssert<(sizeof(int*) > sizeof(int))>(Patate()); // will compile
	return 0;
}
