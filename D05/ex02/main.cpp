#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main()
{
	Bureaucrat	*bureaucrat = new Bureaucrat(138, "Alain");

	std::cout << std::endl;
	std::cout << "Bureaucrat: " << *bureaucrat;
	std::cout << std::endl;

	std::cout << "======== TEST ShrubberyCreationForm ========" << std::endl;

	Form		*shrubberyArgs = new ShrubberyCreationForm("myTarget");


	std::cout << "Args constructor: ";
	std::cout << *(ShrubberyCreationForm*)shrubberyArgs;
	std::cout << std::endl;

	std::cout << "Try to execute form not signed" << std::endl;
	bureaucrat->executeForm(*shrubberyArgs);
	shrubberyArgs->beSigned(*bureaucrat);
	std::cout << std::endl;

	std::cout << "Try to execute form, should fail : grade too low" << std::endl;
	bureaucrat->executeForm(*shrubberyArgs);
	std::cout << std::endl;

	bureaucrat->increaseGrade();
	std::cout << "Bureaucrat grade increased: " << *bureaucrat;
	std::cout << std::endl;

	std::cout << "Try to execute form, should succeed" << std::endl;
	bureaucrat->executeForm(*shrubberyArgs);
	std::cout << std::endl;
/*
	std::cout << "Try to execute form, should fail : ofstream" << std::endl;
	bureaucrat->executeForm(*shrubberyArgs);
	std::cout << std::endl;
*/
	delete shrubberyArgs;

	std::cout << "======== TEST RobotomyRequestForm ========" << std::endl;

	while (bureaucrat->getGrade() > 46)
	{
		bureaucrat->increaseGrade();
	}

	std::cout << std::endl;
	std::cout << "Bureaucrat: " << *bureaucrat;
	std::cout << std::endl;


	Form            *robotomyArgs = new RobotomyRequestForm("myTarget");

	std::cout << "Args constructor: ";
	std::cout << *(RobotomyRequestForm*)robotomyArgs;
	std::cout << std::endl;

	std::cout << "Try to execute form not signed" << std::endl;
	bureaucrat->executeForm(*robotomyArgs);
	robotomyArgs->beSigned(*bureaucrat);
	std::cout << std::endl;


	std::cout << "Try to execute form, should fail : grade too low" << std::endl;
	bureaucrat->executeForm(*robotomyArgs);
	std::cout << std::endl;

	bureaucrat->increaseGrade();
	std::cout << "Bureaucrat grade increased: " << *bureaucrat; 
	std::cout << std::endl;

	std::cout << "Try to execute form, should succeed" << std::endl;
	bureaucrat->executeForm(*robotomyArgs);
	std::cout << std::endl;

	std::cout << "Try to execute form, should fail" << std::endl;
	bureaucrat->executeForm(*robotomyArgs);
	std::cout << std::endl;

	delete robotomyArgs;

	std::cout << "======== TEST PresidentialPardonForm ========" << std::endl;

	while (bureaucrat->getGrade() > 6)
	{
		bureaucrat->increaseGrade();
	}

	std::cout << std::endl;
	std::cout << "Bureaucrat: " << *bureaucrat;
	std::cout << std::endl;


	Form            *presidentialArgs = new PresidentialPardonForm("myTarget");

	std::cout << "Args constructor: ";
	std::cout << *(PresidentialPardonForm*)presidentialArgs;
	std::cout << std::endl;

	std::cout << "Try to execute form not signed" << std::endl;
	bureaucrat->executeForm(*presidentialArgs);
	presidentialArgs->beSigned(*bureaucrat);
	std::cout << std::endl;


	std::cout << "Try to execute form, should fail : grade too low" << std::endl;
	bureaucrat->executeForm(*presidentialArgs);
	std::cout << std::endl;

	bureaucrat->increaseGrade();
	std::cout << "Bureaucrat grade increased: " << *bureaucrat;
	std::cout << std::endl;

	std::cout << "Try to execute form, should succeed" << std::endl;
	bureaucrat->executeForm(*presidentialArgs);
	std::cout << std::endl;

	delete presidentialArgs;

	delete bureaucrat;
	return 0;
}
