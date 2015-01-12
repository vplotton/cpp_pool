#include "Form.hpp"

Form::Form() :
	m_signed(false), m_gradeToSign(1), m_gradeToExecute(1), m_name("* no name *")
{
}


Form::Form(int gradeToSign, int gradeToExecute, std::string name) :
	m_signed(false), m_gradeToSign(gradeToSign), m_gradeToExecute(gradeToExecute), m_name(name)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw (Bureaucrat::GradeTooHighException());
	}
	else if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw (Bureaucrat::GradeTooLowException());
	}
}

Form::Form(Form const & src) :
	m_signed(false), m_gradeToSign(src.getGradeToSign()), m_gradeToExecute(src.getGradeToExecute()), m_name(src.getName())
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

int const	&Form::getGradeToSign() const
{
	return m_gradeToSign;
}
int const	&Form::getGradeToExecute() const
{
	return m_gradeToExecute;
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
		<< ", grade to sign: "
		<< i.getGradeToSign()
		<< ", grade to execute: "
		<< i.getGradeToExecute()
		<< ", "
		<< (i.getSign() == true ? "signed" : "not signed")
		<< std::endl;;
	return (o);
}
