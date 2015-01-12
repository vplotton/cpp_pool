#ifndef FORM_HPP
# define FORM_HPP

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Form
{
	public:
		Form();
		Form(int, int, std::string);
		Form(Form const & src);
		~Form();

		Form & operator=(Form const & rhs);

		bool const		&getSign() const;
		int const		&getGradeToSign() const;
		int const		&getGradeToExecute() const;
		std::string const	&getName() const;

		void		signForm(Bureaucrat const & bureaucrat);

		class GradeTooLowException : public std::exception
		{   
			public:
				GradeTooLowException();

				virtual const char* what() const throw();

		};

	private:
		bool		m_signed;
		int const		m_gradeToSign;
		int const		m_gradeToExecute;
		std::string const	m_name;

};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif /* !FORM_HPP */
