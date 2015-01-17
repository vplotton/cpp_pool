#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() :
	Form(145, 137, "ShrubberyCreationForm"), m_target("default")
{
}


ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target) :
	Form(145, 137, "ShrubberyCreationForm"), m_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src) :
	Form(145, 137, "ShrubberyCreationForm"), m_target(src.getTarget())
{
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

std::string const	&ShrubberyCreationForm::getTarget() const
{
	return m_target;
}

void	ShrubberyCreationForm::executeForm(Bureaucrat const & executor)
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
			std::ofstream file;
			file.exceptions(std::ifstream::failbit | std::ifstream::badbit );

			std::string fileName = getTarget();
			fileName += "_shrubbery";

			file.open(fileName.c_str());

			file << "       t\n"
				"      .#.\n"
				"     .###.\n"
				"    .#%##%.\n"
				"   .%##%###.\n"
				"  .##%###%##.\n"
				" .#%###%##%##.\n"
				"      #\n"
				"      #\n";
			file.close();
		}
	}
}

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & i)
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
