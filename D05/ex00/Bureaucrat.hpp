#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(int, std::string);
		Bureaucrat(Bureaucrat const & src);
		~Bureaucrat();

		Bureaucrat & operator=(Bureaucrat const & rhs);

		int			getGrade() const;
		std::string	getName() const;

		void		increaseGrade();
		void		decreaseGrade();

		class GradeTooHighException : public std::exception
		{
			public:
				GradeTooHighException();

				virtual const char* what() const throw();

		};

		class GradeTooLowException : public std::exception
		{   
			public:
				GradeTooLowException();

				virtual const char* what() const throw();

		};

	private:
		int			m_grade;
		std::string	m_name;

};

std::ostream & operator<<(std::ostream & o, Bureaucrat const & i);

#endif /* !BUREAUCRAT_HPP */
