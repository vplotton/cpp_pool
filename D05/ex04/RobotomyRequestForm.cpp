#include "RobotomyRequestForm.hpp"
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() :
	Form(72, 45, "RobotomyRequestForm"), m_target("default")
{
}


RobotomyRequestForm::RobotomyRequestForm(std::string const & target) :
	Form(72, 45, "RobotomyRequestForm"), m_target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src) :
	Form(72, 45, "RobotomyRequestForm"), m_target(src.getTarget())
{
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm & RobotomyRequestForm::operator=(RobotomyRequestForm const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

std::string const	&RobotomyRequestForm::getTarget() const
{
	return m_target;
}

void	RobotomyRequestForm::executeForm(Bureaucrat const & executor)
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
			if (std::rand() % 2 == 0)
			{
				throw RobotomizationFailure();
			}
			else
			{
				std::cout << executor.getName()
					<< " has been robotomized."
					<< std::endl;
			}
		}
	}
}

RobotomyRequestForm::RobotomizationFailure::RobotomizationFailure() :
	m_msg("RobotomyRequestForm::RobotomizationFailure")
{
}

RobotomyRequestForm::RobotomizationFailure::RobotomizationFailure(RobotomyRequestForm::RobotomizationFailure const & src)
{
	*this = src;
}

RobotomyRequestForm::RobotomizationFailure::~RobotomizationFailure() throw()
{
}

RobotomyRequestForm::RobotomizationFailure        &RobotomyRequestForm::RobotomizationFailure::operator=(RobotomyRequestForm::RobotomizationFailure const & rhs)
{
	(void)rhs;
	return *this;
}

const char*     RobotomyRequestForm::RobotomizationFailure::what() const throw()
{
	return m_msg;
}

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & i)
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
