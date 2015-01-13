#include "PresidentialPardonForm.hpp"
#include <cstdlib>

PresidentialPardonForm::PresidentialPardonForm() :
	Form(25, 5, "PresidentialPardonForm"), m_target("default")
{
}


PresidentialPardonForm::PresidentialPardonForm(std::string const & target) :
	Form(25, 5, "PresidentialPardonForm"), m_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src) :
	Form(25, 5, "PresidentialPardonForm"), m_target(src.getTarget())
{
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

PresidentialPardonForm & PresidentialPardonForm::operator=(PresidentialPardonForm const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

std::string const	&PresidentialPardonForm::getTarget() const
{
	return m_target;
}

void	PresidentialPardonForm::executeForm(Bureaucrat const & executor)
{
	if (getSign() == false)
	{
		throw (Form::IsNotSignedException());
	}
	else
	{
		if (executor.getGrade() > getGradeToExecute())
		{
			throw (Form::GradeTooLowException());
		}
		else
		{
			std::cout << executor.getName()
				<< " has been pardoned by Zafod Beeblebrox."
				<< std::endl;
		}
	}
}

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & i)
{
	o << i.getName()
		<< ", target: "
		<< i.getTarget()
		<< ", grade to sign: "
		<< i.getGradeToSign()
		<< ", grade to execute: "
		<< i.getGradeToExecute()
		<< ", "
		<< (i.getSign() == true ? "signed" : "not signed")
		<< std::endl;;
	return (o);
}
