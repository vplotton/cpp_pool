#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat()
{
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : 
	m_grade(src.getGrade()), m_name(src.getName())
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
		m_grade = rhs.getGrade();
	}
	return (*this);
}

int		Bureaucrat::getGrade() const
{
	return m_grade;
}

std::string const	&Bureaucrat::getName() const
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

Bureaucrat::GradeTooHighException::GradeTooHighException() :
	m_msg("Bureaucrat::GradeTooHighException")
{
}

Bureaucrat::GradeTooHighException::GradeTooHighException(GradeTooHighException const & src)
{
	*this = src;
}

Bureaucrat::GradeTooHighException::~GradeTooHighException() throw()
{
}

Bureaucrat::GradeTooHighException &Bureaucrat::GradeTooHighException::operator=(Bureaucrat::GradeTooHighException const & rhs)
{
	(void)rhs;
	return *this;
}

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return m_msg;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() :
	m_msg("Bureaucrat::GradeTooLowException")
{
}

Bureaucrat::GradeTooLowException::GradeTooLowException(Bureaucrat::GradeTooLowException const & src)
{
	*this = src;
}

Bureaucrat::GradeTooLowException::~GradeTooLowException() throw()
{
}

Bureaucrat::GradeTooLowException	&Bureaucrat::GradeTooLowException::operator=(Bureaucrat::GradeTooLowException const & rhs)
{
	(void)rhs;
	return *this;
}

const char* 	Bureaucrat::GradeTooLowException::what() const throw()
{
	return m_msg;
}


std::ostream & operator<<(std::ostream & o, Bureaucrat const & i)
{
	o << i.getName()
		<< ", bureaucrat grade "
		<< i.getGrade()
		<< std::endl;;
	return (o);
}
