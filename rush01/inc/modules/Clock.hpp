#ifndef CLOCK_HPP
# define CLOCK_HPP

# include "AbstractModule.hpp"

class Clock : public AbstractModule
{
	public:
		Clock();
		virtual ~Clock();

		virtual void    updateData();
		virtual void    initData();

	private:
		void	getDatetime(std::string &, std::string &);
		Clock(Clock const & src);
		Clock & operator=(Clock const & rhs);
};

#endif /* !CLOCK_HPP */
