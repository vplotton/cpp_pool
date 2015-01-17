#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class RobotomyRequestForm : public Form
{
	public:
		RobotomyRequestForm(std::string const &target);
		~RobotomyRequestForm();

		std::string const	&getTarget() const;

		virtual void	executeForm(Bureaucrat const & executor);

		class RobotomizationFailure : public std::exception
		{
			public:
				RobotomizationFailure();
				RobotomizationFailure(RobotomyRequestForm::RobotomizationFailure const &); 
				virtual ~RobotomizationFailure() throw();

				RobotomizationFailure &operator=(RobotomyRequestForm::RobotomizationFailure const &); 

				virtual const char* what() const throw();
			private:
				const char *m_msg;
		};

	private:
		std::string const m_target;

		RobotomyRequestForm();
		RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
};

std::ostream & operator<<(std::ostream & o, RobotomyRequestForm const & i);

#endif /* !ROBOTOMYREQUESTFORM_HPP */
