#include "OfficeBlock.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"

OfficeBlock::OfficeBlock() :
	m_intern(NULL), m_signer(NULL), m_executor(NULL)
{
}

OfficeBlock::OfficeBlock(Intern *& intern, Bureaucrat *& signatory, Bureaucrat *& executor) :
	m_intern(intern), m_signer(signatory), m_executor(executor)
{
}

OfficeBlock::~OfficeBlock()
{
	if (m_intern)
	{
		delete m_intern;
	}

	if (m_signer)
	{
		delete m_signer;
	}

	if (m_executor)
	{
		delete m_executor;
	}
}

void    OfficeBlock::setIntern(Intern *& intern)
{
	if (m_intern)
	{
		delete m_intern;
	}
	m_intern = intern;
}

void    OfficeBlock::setSigner(Bureaucrat *& signer)
{
	if (m_signer)
	{   
		delete m_signer;
	}   
	m_signer = signer;
}

void    OfficeBlock::setExecutor(Bureaucrat *& executor)
{
	if (m_executor)
	{   
		delete m_executor;
	}   
	m_executor = executor;
}

Intern const *		OfficeBlock::getIntern() const
{
	return m_intern;
}

Bureaucrat const *	OfficeBlock::getSigner() const
{
	return m_signer;
}

Bureaucrat const *	OfficeBlock::getExecutor() const
{
	return m_executor;
}


void	OfficeBlock::doBureaucracy(std::string const & formName, std::string const & target) const
{

	if (m_intern == NULL)
	{
		throw (NoInternException());
	}

	if (m_signer == NULL)
	{
		throw (NoSignerException());
	}

	if (m_executor == NULL)
	{
		throw (NoExecutorException());
	}

	Form	*form = m_intern->makeForm(formName, target);

	m_signer->signForm(*form);
	m_executor->executeForm(*form);

	delete form;
}

OfficeBlock::NoInternException::NoInternException() :
	m_msg("OfficeBlock::NoInternException")
{
}

OfficeBlock::NoInternException::NoInternException(OfficeBlock::NoInternException const & src)
{
	*this = src;
}

OfficeBlock::NoInternException::~NoInternException() throw()
{
}

OfficeBlock::NoInternException        &OfficeBlock::NoInternException::operator=(OfficeBlock::NoInternException const & rhs)
{
	(void)rhs;
	return *this;
}

const char*     OfficeBlock::NoInternException::what() const throw()
{
	return m_msg;
}

OfficeBlock::NoSignerException::NoSignerException() :
	m_msg("OfficeBlock::NoSignerException")
{
}

OfficeBlock::NoSignerException::NoSignerException(OfficeBlock::NoSignerException const & src)
{
	*this = src;
}

OfficeBlock::NoSignerException::~NoSignerException() throw()
{
}

OfficeBlock::NoSignerException        &OfficeBlock::NoSignerException::operator=(OfficeBlock::NoSignerException const & rhs)
{
	(void)rhs;
	return *this;
}

const char*     OfficeBlock::NoSignerException::what() const throw()
{
	return m_msg;
}

OfficeBlock::NoExecutorException::NoExecutorException() :
	m_msg("OfficeBlock::NoExecutorException")
{
}

OfficeBlock::NoExecutorException::NoExecutorException(OfficeBlock::NoExecutorException const & src)
{
	*this = src;
}

OfficeBlock::NoExecutorException::~NoExecutorException() throw()
{
}

OfficeBlock::NoExecutorException        &OfficeBlock::NoExecutorException::operator=(OfficeBlock::NoExecutorException const & rhs)
{
	(void)rhs;
	return *this;
}

const char*     OfficeBlock::NoExecutorException::what() const throw()
{
	return m_msg;
}

std::ostream & operator<<(std::ostream & o, OfficeBlock const & i)
{
	if (i.getSigner() && i.getExecutor())
	{
		o << "OfficeBlock:" << std::endl
			<< "	Inter: [ nobody ]" << std::endl
			<< "	Signer: " << *i.getSigner()
			<< "	Executor: " << *i.getExecutor() << std::endl;
	}
	return (o);
}

OfficeBlock::OfficeBlock(OfficeBlock const & src) :
	m_intern(NULL), m_signer(NULL), m_executor(NULL)
{
	*this = src;
}

OfficeBlock & OfficeBlock::operator=(OfficeBlock const & rhs)
{
	if (this != &rhs)
	{
	}
	return (*this);
}

