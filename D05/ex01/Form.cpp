#include "Form.hpp"

Form::Form() :
	m_signed(false), m_gradeToSign(1), m_name("* no name *")
{
}


Form::Form(int grade, std::string name) :
	m_signed(false), m_gradeToSign(grade), m_name(name)
{
	if (grade < 1)
	{
		throw (Bureaucrat::GradeTooHighException());
	}
	else if (grade > 150)
	{
		throw (Bureaucrat::GradeTooLowException());
	}
}

Form::Form(Form const & src) :
	m_signed(false), m_gradeToSign(src.getGrade()), m_name(src.getName())
{
	*this = src;
}

Form::~Form()
{
}

Form & Form::operator=(Form const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

bool const	&Form::getSign() const
{
	return m_signed;
}

int const	&Form::getGrade() const
{
	return m_gradeToSign;
}

std::string const	&Form::getName() const
{
	return m_name;
}

void		Form::signForm(Bureaucrat const & bureaucrat)
{
	try
	{
		if (bureaucrat.getGrade() > m_gradeToSign)
		{
			throw (GradeTooLowException());
		}
		else
		{
			m_signed = true;
			std::cout << bureaucrat.getName()
				<< " signs "
				<< m_name
				<< std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << bureaucrat.getName()
			<< " cannot sign "
			<< m_name
			<< " because "
			<< e.what()
			<< std::endl;
	}
}

Form::GradeTooLowException::GradeTooLowException()
{
}

const char*	Form::GradeTooLowException::what() const throw()
{
	        return "grade is too low";
}


std::ostream & operator<<(std::ostream & o, Form const & i)
{
	o << i.getName()
		<< ", grade to apply: "
		<< i.getGrade()
		<< ", "
		<< (i.getSign() == true ? "signed" : "not signed")
		<< std::endl;;
	return (o);
}
