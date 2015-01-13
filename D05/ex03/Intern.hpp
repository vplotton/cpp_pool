#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <exception>

/*
typedef  void	(Form::*RequestForm)(std::string const &);
*/
class Form;
class Intern;

typedef struct  s_createForms
{
	std::string     name;   
	Form    * (Intern::*getForm)(std::string const &) const;
}               t_createForms;


class Intern
{
	public:
		Intern();
		Intern(Intern const & src);
		~Intern();

		Intern & operator=(Intern const & rhs);

		Form	* makeForm(std::string const &, std::string const &) const;

		static t_createForms const	createForms[];

		class FormNotFoundException : public std::exception
	{
		public:
			FormNotFoundException();
			FormNotFoundException(Intern::FormNotFoundException const &); 
			virtual ~FormNotFoundException() throw();

			FormNotFoundException &operator=(Intern::FormNotFoundException const &); 

			virtual const char* what() const throw();
		private:
			const char *m_msg;
	};
		Form	* createPresidentialForm(std::string const &) const;
		Form	* createShrubberyForm(std::string const &) const;
		Form	* createRobotomyForm(std::string const &) const;
};

/*std::ostream & operator<<(std::ostream & o, Intern const & i);*/

#endif /* !INTERN_HPP */
