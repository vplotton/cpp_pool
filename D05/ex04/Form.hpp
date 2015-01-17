#ifndef FORM_HPP
# define FORM_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
	public:
		Form(int, int, std::string);
		virtual ~Form();

		bool const		&getSign() const;
		int const		&getGradeToSign() const;
		int const		&getGradeToExecute() const;
		std::string const	&getName() const;

		void		beSigned(Bureaucrat const & bureaucrat);
		virtual void    executeForm(Bureaucrat const & executor) = 0;

		class GradeTooLowException : public std::exception
		{
			public:
				GradeTooLowException();
				GradeTooLowException(Form::GradeTooLowException const &); 
				virtual ~GradeTooLowException() throw();

				GradeTooLowException &operator=(Form::GradeTooLowException const &); 

				virtual const char* what() const throw();
			private:
				const char *m_msg;
		};

		class IsNotSignedException : public std::exception
		{
			public:
				IsNotSignedException();
				IsNotSignedException(Form::IsNotSignedException const &); 
				virtual ~IsNotSignedException() throw();

				IsNotSignedException &operator=(Form::IsNotSignedException const &); 

				virtual const char* what() const throw();
			private:
				const char *m_msg;
		};

	private:
		bool		m_signed;
		int const		m_gradeToSign;
		int const		m_gradeToExecute;
		std::string const	m_name;

		Form();
		Form(Form const & src);
		Form & operator=(Form const & rhs);
};

std::ostream & operator<<(std::ostream & o, Form const & i);

#endif /* !FORM_HPP */
