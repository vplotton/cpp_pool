#include "Logger.hpp"
#include <fstream>
#include <iostream>

Logger::Logger()
{
}

Logger::~Logger()
{
}

void	Logger::log(std::string const & dest, std::string const & message)
{
	t_logFunc logFunctions[2] =
	{
		{ "file", &Logger::logToFile },
		{ "console", &Logger::logToConsole }
	};
	bool	funcFound = false;

	for (int i = 0; i < 2 ; ++i)
	{
		if (logFunctions[i].name.compare(dest) == 0)
		{
			funcFound = true;
			(this->*(logFunctions[i].func))(message);
		}
	}
	if (funcFound == false)
	{
		std::cout << "No log functions with this name." << std::endl;
	}
}

void	Logger::logToFile(std::string log)
{
	std::ofstream	logFile;

	logFile.open("log.txt", std::fstream::in | std::fstream::out | std::fstream::app);
	if (!logFile.is_open())
	{
		std::cout << "Could not open \"log.txt\"" << std::endl;
		return ;
	}

	logFile << log << std::endl;
	if (logFile.bad())
	{
		std::cout << "Could not save to \"log.txt\"";
		logFile.close();
		std::cout << "\"log.txt\" has been closed." << std::endl;
		return ;
	}
	logFile.close();
}

void	Logger::logToConsole(std::string log)
{
	std::cout << log << std::endl;
}
