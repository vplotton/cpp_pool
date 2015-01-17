#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class PresidentialPardonForm : public Form
{
	public:
		PresidentialPardonForm(std::string const &target);
		~PresidentialPardonForm();

		std::string const	&getTarget() const;

		virtual void	executeForm(Bureaucrat const & executor);

	private:
		std::string const m_target;

		PresidentialPardonForm();
		PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
};

std::ostream & operator<<(std::ostream & o, PresidentialPardonForm const & i);

#endif /* !PRESIDENTIALPARDONFORM_HPP */
