#ifndef OFFICEBLOCK_HPP
# define OFFICEBLOCK_HPP

#include <exception>
#include <iostream>

class Intern;
class Bureaucrat;

class OfficeBlock
{
	public:
		OfficeBlock();
		OfficeBlock(Intern *& intern, Bureaucrat *& signer, Bureaucrat *& executor);
		~OfficeBlock();

		void	setIntern(Intern *&);
		void	setSigner(Bureaucrat *&);
		void	setExecutor(Bureaucrat *&);
		Intern const *		getIntern() const;
		Bureaucrat const *	getSigner() const;
		Bureaucrat const *	getExecutor() const;

		void	doBureaucracy(std::string const &, std::string const &) const;

		class NoInternException : public std::exception
		{
			public:
				NoInternException();
				NoInternException(OfficeBlock::NoInternException const &); 
				virtual ~NoInternException() throw();

				NoInternException &operator=(OfficeBlock::NoInternException const &); 

				virtual const char* what() const throw();
			private:
				const char *m_msg;
		};

		class NoSignerException : public std::exception
		{   
			public:
				NoSignerException();
				NoSignerException(OfficeBlock::NoSignerException const &); 
				virtual ~NoSignerException() throw();

				NoSignerException &operator=(OfficeBlock::NoSignerException const &); 

				virtual const char* what() const throw();
			private:
				const char *m_msg;
		}; 

		class NoExecutorException : public std::exception
		{   
			public:
				NoExecutorException();
				NoExecutorException(OfficeBlock::NoExecutorException const &); 
				virtual ~NoExecutorException() throw();

				NoExecutorException &operator=(OfficeBlock::NoExecutorException const &); 

				virtual const char* what() const throw();
			private:
				const char *m_msg;
		}; 

	private:
		Intern		*m_intern;
		Bureaucrat	*m_signer;
		Bureaucrat	*m_executor;

		OfficeBlock & operator=(OfficeBlock const & rhs);
		OfficeBlock(OfficeBlock const & src);
};

std::ostream & operator<<(std::ostream & o, OfficeBlock const & i);

#endif /* !OFFICEBLOCK_HPP */
