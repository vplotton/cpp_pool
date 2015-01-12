#include "../Movement.hpp"
#include <sstream>
#include <string>

typedef struct	s_test
{
	Movement	*move;
	std::string	name;
	std::string	test;
	Movement::func;
	int			arg;
}				t_test;

t_test			tests[] =
{
	{ movHeapDefault = new Movement(), "movHeapDefault creation = ",
		"Movement - [ x : 0 ] [ y : 0 ]", NULL },
	{ movHeapArgs = new Movement(5, 5), "movHeapArgs creation = ",
		"Movement - [ x : 5 ] [ y : 5 ]", NULL },
	{ movHeapCopy = new Movement(*movHeapArgs), "movHeapCopy creation = ",
		"Movement - [ x : 5 ] [ y : 5 ]", NULL },
	{ movHeapArgs, "movHeapArgs setX = ",
		"Movement - [ x : 3 ] [ y : 5 ]", &Movement::setX

};


int		main()
{
	std::ostringstream	input;
	std::streambuf*     oldbuf  = std::cout.rdbuf( input.rdbuf() );

	std::string			testStrings[] =
	{
		"Movement - [ x : 0 ] [ y : 0 ]",
		"Movement - [ x : 0 ] [ y : 0 ]",
		"Movement - [ x : 5 ] [ y : 5 ]",
		"Movement - [ x : 5 ] [ y : 5 ]",
		"Movement - [ x : 3 ] [ y : 5 ]",
		"Movement - [ x : 3 ] [ y : 3 ]",
		"Movement - [ x : 3 ] [ y : 2 ]",
		"Movement - [ x : 3 ] [ y : 3 ]",
		"Movement - [ x : 2 ] [ y : 3 ]",
		"Movement - [ x : 3 ] [ y : 3 ]",
	};

	std::string			testNames[] = 
	{
		"movStack creation = ",
		"movHeapDefault creation = ",
		"movHeapArgs creation = ",
		"movHeapCopy creation = ",
		"movHeapArgs setX = ",
		"movHeapArgs setY = ",
		"movHeapArgs goUp = ",
		"movHeapArgs goDown = ",
		"movHeapArgs goLeft = ",
		"movHeapArgs goRight = "
	}



	Movement    movStack;

	Movement    *movHeapDefault = new Movement();

	Movement    *movHeapArgs = new Movement(5, 5);

	Movement    *movHeapCopy = new Movement(*movHeapArgs);

	std::string str;
	while(std::getline(redirectStream, str))
	{
	}

	input << movStack;
	std::cout << "movStack creation = "
		<< (input.str.compare(stringTests[0]) == 0 ? "true" : "false")
		<< std::endl;

	input << *movHeapDefault;
	std::cout << "movHeapDefault creation = "
		<< (input.str.compare(stringTests[1]) == 0 ? "true" : "false")
		<< std::endl;

	input << *movHeapArgs;
	std::cout << "movHeapArgs creation = "
		<< (input.str.compare(stringTests[2]) == 0 ? "true" : "false")
		<< std::endl;

	input << *movHeapCopy;
	std::cout << "movHeapCopy creation = "
		<< (input.str.compare(stringTests[3]) == 0 ? "true" : "false")
		<< std::endl;

	movHeapArgs.setX(3);
	std::cout << "movHeapArgs setX = "
		<< (input.str.compare(stringTests[4]) == 0 ? "true" : "false")
		<< std::endl;

	movHeapArgs.setY(3);
	std::cout << "movHeapArgs setY = "
		<< (input.str.compare(stringTests[5]) == 0 ? "true" : "false")
		<< std::endl;

	movHeapArgs.goUp();
	std::cout << "movHeapArgs goUp = "
		<< (input.str.compare(stringTests[6]) == 0 ? "true" : "false")
		<< std::endl;

	movHeapArgs.goDown();
	std::cout << "movHeapArgs goDown = "
		<< (input.str.compare(stringTests[7]) == 0 ? "true" : "false")
		<< std::endl;

	movHeapArgs.goLeft();
	std::cout << "movHeapArgs goLeft = "
		<< (input.str.compare(stringTests[8]) == 0 ? "true" : "false")
		<< std::endl;

	movHeapArgs.goRight();
	std::cout << "movHeapArgs goRight = "
		<< (input.str.compare(stringTests[9]) == 0 ? "true" : "false")
		<< std::endl;

	delete movHeapDefault;
	delete movHeapArgs;
	delete movHeapCopy;

	return 0;
}
