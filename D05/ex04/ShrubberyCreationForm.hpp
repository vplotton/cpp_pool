#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class ShrubberyCreationForm : public Form
{
	public:
		ShrubberyCreationForm(std::string const &target);
		~ShrubberyCreationForm();

		std::string const	&getTarget() const;

		virtual void	executeForm(Bureaucrat const & executor);

	private:
		std::string const m_target;

		ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm & operator=(ShrubberyCreationForm const & rhs);
};

std::ostream & operator<<(std::ostream & o, ShrubberyCreationForm const & i);

#endif /* !SHRUBBERYCREATIONFORM_HPP */
