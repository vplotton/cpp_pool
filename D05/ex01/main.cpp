#include "Bureaucrat.hpp"
#include "Form.hpp"

int		main()
{
	Bureaucrat	*bureaucrat = new Bureaucrat(35, "Alain");


	std::cout << std::endl;
	std::cout << "Bureaucrat: " << *bureaucrat;
	std::cout << std::endl;

	Form		*form = new Form(34, 40, "contract");

	std::cout << "Form: ";
	std::cout << *form;
	std::cout << std::endl;

	std::cout << "Try to sign form [ should fail ]" << std::endl;
	bureaucrat->signForm(*form);
	std::cout << std::endl;

	bureaucrat->increaseGrade();
	std::cout << "Bureaucrat grade increased: " << *bureaucrat;
	std::cout << std::endl;

	std::cout << "Try to sign form [ should succeed ]" << std::endl;
	bureaucrat->signForm(*form);
	std::cout <<std::endl;

	std::cout << *form;

	delete form;

	delete bureaucrat;
	return 0;
}
