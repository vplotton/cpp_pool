#include "Bureaucrat.hpp"

int		main()
{
	Bureaucrat	*bureaucratDefault = new Bureaucrat();
	Bureaucrat	*bureaucratArgs = new Bureaucrat(150, "Alain");
	Bureaucrat	*bureaucratCopy = new Bureaucrat(*bureaucratArgs);

	std::cout << "Default constructor: ";
	std::cout << *bureaucratDefault;
	std::cout << std::endl;

	std::cout << "Args constructor: ";
	std::cout << *bureaucratArgs;
	std::cout << std::endl;
	
	std::cout << "Copy constructor: ";
	std::cout << *bureaucratCopy;
	std::cout << std::endl;

	std::cout << "Decrease grade: ";
	bureaucratArgs->decreaseGrade();
	std::cout << *bureaucratArgs;
	std::cout << std::endl;

	std::cout << "Increase grade: ";
	bureaucratArgs->increaseGrade();
	std::cout << *bureaucratArgs;
	std::cout << std::endl;

	std::cout << "Try to decrease 's grade: " << std::endl;
	try
	{
		bureaucratDefault->decreaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "Check if grade decreased: ";
	std::cout << *bureaucratDefault;
	std::cout << std::endl;

	std::cout << "Try to increase Alain's grade: " << std::endl;
	try
	{
		bureaucratArgs->increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
	std::cout << "Check if grade increased: ";
	std::cout << *bureaucratArgs;
	std::cout << std::endl;

	std::cout << "Try to instanciate new Bureaucrat with Grade Too High: " <<std::endl;
	Bureaucrat	*bureaucratTooHigh = NULL;
	try
	{
		bureaucratTooHigh = new Bureaucrat(151, "TooHigh");
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
		bureaucratTooLow = new Bureaucrat(0, "TooLow");
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


	delete bureaucratDefault;
	delete bureaucratArgs;
	delete bureaucratCopy;
	return 0;
}
