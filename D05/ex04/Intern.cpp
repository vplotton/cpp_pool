#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

t_createForms const	Intern::createForms[] =
{
	{ "presidential pardon", &Intern::createPresidentialForm },
	{ "robotomy request", &Intern::createRobotomyForm },
	{ "shrubbery creation", &Intern::createShrubberyForm }
};


Intern::Intern()
{
}

Intern::Intern(Intern const & src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern & Intern::operator=(Intern const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

Form	* Intern::createPresidentialForm(std::string const &target) const
{
	Form	*newForm = new PresidentialPardonForm(target);

	return (newForm);
}

Form	* Intern::createRobotomyForm(std::string const &target) const
{
	Form	*newForm = new RobotomyRequestForm(target);
	
	return (newForm);
}

Form	* Intern::createShrubberyForm(std::string const &target) const
{
	Form	*newForm = new ShrubberyCreationForm(target);

	return (newForm);
}

Form	* Intern::makeForm(std::string const &formType, std::string const &target) const
{
	Form	*newForm;
	bool	formNotFound = true;

	for (int i = 0 ; i < 3 ; ++i)
	{
		if (createForms[i].name.compare(formType) == 0)
		{
			formNotFound = false;
			newForm = (this->*(createForms[i].getForm))(target);
			std::cout << "Intern creates " << newForm->getName() << std::endl;
		}
	}

	if (formNotFound == true)
	{
		throw (FormNotFoundException());
	}
	return newForm;
}

Intern::FormNotFoundException::FormNotFoundException() :
	m_msg("Form::FormNotFoundException")
{
}

Intern::FormNotFoundException::FormNotFoundException(Intern::FormNotFoundException const & src)
{
	*this = src;
}

Intern::FormNotFoundException::~FormNotFoundException() throw()
{
}

Intern::FormNotFoundException        &Intern::FormNotFoundException::operator=(Intern::FormNotFoundException const & rhs)
{
	(void)rhs;
	return *this;
}

const char*     Intern::FormNotFoundException::what() const throw()
{
	return m_msg;
}

/*
   std::ostream & operator<<(std::ostream & o, Intern const & i)
   {
   o << "Don't forget to change this.";
   return (o);
   }
 */
