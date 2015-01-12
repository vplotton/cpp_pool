#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() :
	m_grade(1), m_name("* no name *")
{
}


Bureaucrat::Bureaucrat(int grade, std::string name) :
	m_grade(grade), m_name(name)
{
	if (grade < 1)
	{
		throw (GradeTooHighException());
	}
	else if (grade > 150)
	{
		throw (GradeTooLowException());
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const & src)
{
	*this = src;
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs)
{
	if (this != &rhs)
	{
		m_grade = rhs.m_grade;
		m_name = rhs.m_name;
	}
	return (*this);
}

int		Bureaucrat::getGrade() const
{
	return m_grade;
}

std::string	Bureaucrat::getName() const
{
	return m_name;
}

void		Bureaucrat::increaseGrade()
{
	int	grade = m_grade - 1;

	if (grade < 1)
	{   
		throw (GradeTooHighException());
	}
	else
	{
		--m_grade;
	}
}

void		Bureaucrat::decreaseGrade()
{
	int	grade = m_grade + 1;

	if (grade > 150)
	{   
		throw (GradeTooLowException());
	}   
	else
	{
		++m_grade;
	}
}

Bureaucrat::GradeTooHighException::GradeTooHighException()
{
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade Too High";
}

Bureaucrat::GradeTooLowException::GradeTooLowException()
{
}

const char* 	Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade Too Low";
}



std::ostream & operator<<(std::ostream & o, Bureaucrat const & i)
{
	o << i.getName()
		<< ", bureaucrat grade "
		<< i.getGrade()
		<< std::endl;;
	return (o);
}
