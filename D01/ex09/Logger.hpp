#ifndef LOGGER_HPP
# define LOGGER_HPP

#include <string>

class Logger
{
	public:
		Logger();
		~Logger();
		void	log(std::string const & dest, std::string const & message);

	private:
		void	logToFile(std::string log);
		void	logToConsole(std::string log);
};

typedef struct s_logFunc
{
	std::string name;
	void        (Logger::*func)(std::string);
}               t_logFunc;

#endif /* !LOGGER_HPP */
