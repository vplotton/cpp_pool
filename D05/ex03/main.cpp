#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main()
{
	Intern	intern;

	std::cout << std::endl;
	std::cout << "======== TEST ShrubberyCreationForm ========" << std::endl;

	Form	*shrubberyForm = intern.makeForm("shrubbery creation", "target shrubbery");
	std::cout << std::endl;

	delete shrubberyForm;

	std::cout << "======== TEST RobotomyRequestForm ========" << std::endl;

	Form	*robotomyForm = intern.makeForm("robotomy request", "target robotomy");
	std::cout << std::endl;
	
	delete robotomyForm;

	std::cout << "======== TEST PresidentialPardonForm ========" << std::endl;

	Form	*presidentialForm = intern.makeForm("presidential pardon", "target presidential");
	std::cout << std::endl;
	
	delete presidentialForm;

	std::cout << "======== TEST UnknownForm ========" << std::endl;
	
	try
	{
		Form	*unknownForm = intern.makeForm("unknown pardon", "target unknown");
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	return 0;
}
