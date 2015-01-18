#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
	public:
		Bureaucrat(int, std::string);
		~Bureaucrat();


		int			getGrade() const;
		std::string const	&getName() const;

		void		increaseGrade();
		void		decreaseGrade();

		void		signForm(Form &) const;

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();
				GradeTooHighException(Bureaucrat::GradeTooHighException const &);
				virtual ~GradeTooHighException() throw();

				GradeTooHighException &operator=(Bureaucrat::GradeTooHighException const &);

				virtual const char* what() const throw();
			private:
				const char *m_msg;
		};

		class GradeTooLowException : public std::exception
		{   
			public:
				GradeTooLowException();
				GradeTooLowException(Bureaucrat::GradeTooLowException const &);
				virtual ~GradeTooLowException() throw();

				GradeTooLowException &operator=(Bureaucrat::GradeTooLowException const &);

				virtual const char* what() const throw();
			private:
				const char *m_msg;
		};

	private:
		int			m_grade;
		std::string const	m_name;

		Bureaucrat();
		Bureaucrat(Bureaucrat const & src);
		Bureaucrat & operator=(Bureaucrat const & rhs);

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i);

#endif /* !BUREAUCRAT_HPP */
