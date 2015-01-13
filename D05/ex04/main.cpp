#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "OfficeBlock.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int		main()
{
	Intern		*intern = new Intern();
	Bureaucrat	*signer = new Bureaucrat(150, "Signer");
	Bureaucrat	*executor = new Bureaucrat(150, "Executor");
	

	OfficeBlock	*officeBlock = new OfficeBlock();
	std::cout << std::endl;

	std::cout << "[ TEST ] Intern == NULL " << std::endl;
	try
	{
		officeBlock->doBureaucracy("shrubbery creation", "target shrubbery");
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	
	std::cout << "[ TEST ] Signer == NULL " << std::endl;
	officeBlock->setIntern(intern);
	try 
	{   
		officeBlock->doBureaucracy("shrubbery creation", "target shrubbery");
	}   
	catch (std::exception &e)
	{   
		std::cerr << e.what() << std::endl;
	}   
	std::cout << std::endl;
	officeBlock->setSigner(signer);
	
	std::cout << "[ TEST ] Executor == NULL " << std::endl;
	try 
	{   
		officeBlock->doBureaucracy("shrubbery creation", "target shrubbery");
	}   
	catch (std::exception &e)
	{   
		std::cerr << e.what() << std::endl;
	}   
	std::cout << std::endl;
	officeBlock->setExecutor(executor);

	std::cout << "[ TEST ] Intern Form invalid " << std::endl;
	try                
	{                                
		officeBlock->doBureaucracy("shrubb  ery creation", "target shrubbery");           
	}                                                                
	catch (std::exception &e)                        
	{                                        
		std::cerr << e.what() << std::endl;                                                     
	}                                                                        
	std::cout << std::endl;

	std::cout << "[ TEST ] Signer GradeTooLow " << std::endl;
	try                                             
	{                                                               
		officeBlock->doBureaucracy("shrubbery creation", "target shrubbery");           
	}                                                                                               
	catch (std::exception &e)                               
	{                                                                       
		std::cerr << e.what() << std::endl;                                                     
	}                                                                                                       
	std::cout << std::endl;

	while (signer->getGrade() > 50)
	{
		signer->increaseGrade();
	}

	std::cout << "[ TEST ] Executor GradeTooLow " << std::endl;
	try                
	{                                
		officeBlock->doBureaucracy("shrubbery creation", "target shrubbery");           
	}                                                                
	catch (std::exception &e)                        
	{                                        
		std::cerr << e.what() << std::endl;                                                     
	}                                                                        
	std::cout << std::endl;

	while (executor->getGrade() > 50)
	{
		executor->increaseGrade();
	}

	std::cout << "[ TEST ] No error" << std::endl;
	try
	{
		officeBlock->doBureaucracy("shrubbery creation", "target shrubbery");
	}
	catch (std::exception &e)                        
	{                                        
		std::cerr << e.what() << std::endl;                                                     
	} 
	std::cout << std::endl;

	return 0;
}
