#include "Bureaucrat.hpp"

int		main()
{
	Bureaucrat	*bureaucratArgs = new Bureaucrat(1, "Alain");

	std::cout << "Args constructor: ";
	std::cout << *bureaucratArgs;
	std::cout << std::endl;

	std::cout << "Decrease grade: ";
	bureaucratArgs->decreaseGrade();
	std::cout << *bureaucratArgs;
	std::cout << std::endl;

	std::cout << "Increase grade: ";
	bureaucratArgs->increaseGrade();
	std::cout << *bureaucratArgs;
	std::cout << std::endl;

	std::cout << "Try to increase " << bureaucratArgs->getName() << "'s grade: " << std::endl;
	try
	{
		bureaucratArgs->increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "Check if grade not increased: ";
	std::cout << *bureaucratArgs;
	std::cout << std::endl;

	while (bureaucratArgs->getGrade() < 150)
	{
		bureaucratArgs->decreaseGrade();
	}

	std::cout << "Try to decrease " << bureaucratArgs->getName() << "'s grade: " << std::endl;
	try
	{
		bureaucratArgs->decreaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "Check if grade not decreased: ";
	std::cout << *bureaucratArgs;
	std::cout << std::endl;

	std::cout << "Try to instanciate new Bureaucrat with Grade Too High: " <<std::endl;
	Bureaucrat	*bureaucratTooHigh = NULL;
	try
	{
		bureaucratTooHigh = new Bureaucrat(0, "TooHigh");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	if (bureaucratTooHigh)
	{
		std::cout << *bureaucratTooHigh;
	}
	else
	{
		std::cout << "BureaucratTooHigh was not created" << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Try to instanciate new Bureaucrat with Grade Too Low: " <<std::endl;
	Bureaucrat	*bureaucratTooLow = NULL;
	try
	{
		bureaucratTooLow = new Bureaucrat(151, "TooLow");
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	if (bureaucratTooLow)
	{
		std::cout << *bureaucratTooLow;
	}
	else
	{
		std::cout << "BureaucratTooLow was not created" << std::endl;
	}
	std::cout << std::endl;


	delete bureaucratArgs;

	return 0;
}
