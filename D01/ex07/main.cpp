#include <iostream>
#include <fstream>
#include <string>

bool	openIfstream(std::ifstream &file, std::string fileName)
{
	file.open(fileName.c_str());
	if (!file.is_open())
	{
		std::cout << "Could not open \"" << fileName << "\"" << std::endl;
		return false;
	}

	return (true);
}

bool	openOfstream(std::ofstream &file, std::string fileName)
{
	file.open(fileName.c_str());
	if (!file.is_open())
	{
		std::cout << "Could not open \"" << fileName << "\"" << std::endl;
		return false;
	}

	return (true);
}

bool	writeToFile(std::ofstream &output, std::string fileName, std::string line)
{
	output << line << std::endl;
	if (output.bad())
	{
		std::cout << "Could not save to \"" << fileName << "\"";
		output.close();
		std::cout << "\"" << fileName << "\" has been closed." << std::endl;
		return (false);
	}
	return (true);
}

bool	replace(std::ofstream &output, std::ifstream &input, std::string find, std::string replacement, std::string fileName)
{
	std::string line;
	size_t len = find.length();

	std::cout << "Replacing " << find << " with " << replacement << " in " << fileName << std::endl;
	while (std::getline(input, line))
	{
		std::cout << "Current line: " << line << std::endl;
		while (true)
		{
			size_t pos = line.find(find);
			if (pos != std::string::npos)
			{
				line.replace(pos, len, replacement);
			}
			else 
			{
				break;
			}
		}

		if (writeToFile(output, fileName, line) == false)
		{
			return (false);
		}
	}

	return (true);
}

bool	handleFiles(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "wrong number of arguments." << std::endl;
		return (false);
	}
	std::ifstream	input;
	std::ofstream	output;
	std::string		inputName(av[1]);
	std::string		outputName(inputName + ".replace");
	std::string		find(av[2]);
	std::string		replacement(av[3]);
	std::string		fileName(av[1]);

	if (openIfstream(input, inputName) == false || openOfstream(output, outputName) == false)
	{
		return (false);
	}

	if (replace(output, input, find, replacement, fileName) == false)
	{
		return (false);
	}

	return (true);
}

int		main(int ac, char **av)
{
	if (handleFiles(ac, av) == false)
	{
		return (0);
	}
	return (0);
}
