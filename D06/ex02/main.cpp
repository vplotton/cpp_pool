#include <iostream>
#include <cstdlib>
#include "A.hpp"
#include "B.hpp"
#include "c.hpp"

static int	last = 1;

Base	*generate()
{
	int		randType;

	srand(time(NULL) * last);
	last = std::rand();

	randType = last % 3;
	if (randType == 0)
	{
		std::cout << "[ TEST ] - A generated" << std::endl;
		return reinterpret_cast<Base*>(new A);
	}
	else if (randType == 1)
	{
		std::cout << "[ TEST ] - B generated" << std::endl;
		return reinterpret_cast<Base*>(new B);
	}
	std::cout << "[ TEST ] - C generated" << std::endl;
	return reinterpret_cast<Base*>(new C);
}

void identify_from_pointer( Base * p )
{
	if (dynamic_cast<A*> (p) != NULL)
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*> (p) != NULL)
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*> (p) != NULL)
	{
		std::cout << "C" << std::endl;
	}
}

void identify_from_reference( Base & p )
{
	try
	{
		A	& a = dynamic_cast<A&> (p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (...)
	{
	}
	try
	{
		B   & b = dynamic_cast<B&> (p);
		std::cout << "B" << std::endl;
	}
	catch (...)
	{
	}
	try
	{
		C	&c = dynamic_cast<C&> (p);
		std::cout << "C" << std::endl;
	}
	catch (...)
	{
	}
}

int		main()
{
	Base	*test1 = generate();
	identify_from_pointer(test1);
	std::cout << std::endl;

	Base	*test2 = generate();
	identify_from_pointer(test2);
	std::cout << std::endl;

	Base	*test3 = generate();
	identify_from_pointer(test3);
	std::cout << std::endl;

	Base	*test4 = generate();
	identify_from_pointer(test4);
	std::cout << std::endl;

	A	a;
	B	b;
	C	c;


	std::cout << std::endl;
	
	std::cout << "[ TEST ] - class A" << std::endl;
	identify_from_reference(reinterpret_cast<Base&>(a));
	std::cout << std::endl;
	
	std::cout << "[ TEST ] - class A" << std::endl;
	identify_from_reference(reinterpret_cast<Base&>(b));
	std::cout << std::endl;
	
	std::cout << "[ TEST ] - class A" << std::endl;
	identify_from_reference(reinterpret_cast<Base&>(c));
	std::cout << std::endl;

	return 0;
}
