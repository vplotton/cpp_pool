#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main()
{
	Bureaucrat	*bureaucrat = new Bureaucrat(35, "Alain");

	Form		*formDefault = new Form();
	Form		*formArgs = new Form(34, 40, "contract");
	Form		*formCopy = new Form(*formArgs);

	std::cout << "Bureaucrat: " << *bureaucrat;
	std::cout << std::endl;

	std::cout << "Default constructor: ";
	std::cout << *formDefault;
	std::cout << std::endl;

	std::cout << "Args constructor: ";
	std::cout << *formArgs;
	std::cout << std::endl;
	
	std::cout << "Copy constructor: ";
	std::cout << *formCopy;
	std::cout << std::endl;

	std::cout << "Try to sign form, should fail" << std::endl;
	formArgs->signForm(*bureaucrat);
	std::cout << std::endl;

	bureaucrat->increaseGrade();
	std::cout << "Bureaucrat grade increased: " << *bureaucrat;
	std::cout << "Try to sign form, should work" << std::endl;
	formArgs->signForm(*bureaucrat);
	std::cout <<std::endl;

	std::cout << *formArgs;

	delete formDefault;
	delete formArgs;
	delete formCopy;

	delete bureaucrat;
	return 0;
}
