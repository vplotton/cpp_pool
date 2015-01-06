#include "Logger.hpp"

int		main()
{
	Logger logger;

	logger.log("console", "message console");
	logger.log("file", "message file");
	logger.log("fi le", "message file");
	return (0);
}
