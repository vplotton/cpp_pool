#include <iostream>
#include <fstream>
#include <string>

void	createNames(std::string name, std::string &nameUpper, std::string &nameFirstUpper)
{
	for (int i = 0; i < name.size() ; ++i)
	{
		if (i == 0)
		{
			nameFirstUpper += std::toupper(name.at(0));
		}
		else
		{
			nameFirstUpper += std::tolower(name.at(i));
		}
		nameUpper += std::toupper(name.at(i));
	}
}

void	createCpp(std::string nameFirstUpper)
{
	std::ofstream	file;
	std::string	fileName(nameFirstUpper + std::string(".cpp"));

	file.open(fileName.c_str());
	if (!file.is_open())
		return ;
	file << "#include \"" << nameFirstUpper << ".hpp\"" << std::endl;
	file << std::endl;
	file << nameFirstUpper << "::" << nameFirstUpper << "()" << std::endl;
	file << "{" << std::endl;
	file << "}" << std::endl;
	file << std::endl;
	file << nameFirstUpper << "::" << nameFirstUpper << "(" << nameFirstUpper << " const & src)" << std::endl;
	file << "{" << std::endl;
	file << "	*this = src;" << std::endl;
	file << "}" << std::endl;
	file << std::endl;
	file << nameFirstUpper << "::~" << nameFirstUpper << "()" << std::endl;
	file << "{" << std::endl;
	file << "}" << std::endl;
	file << std::endl;
	file << nameFirstUpper << " & " << nameFirstUpper << "::operator=(" << nameFirstUpper << " const & rhs)" << std::endl;
	file << "{" << std::endl;
	file << "	if (this != &rhs)" << std::endl;
	file << "	{" << std::endl;
	file << "		/* my implementation, don't forget to change this. */" << std::endl;
	file << "	}" << std::endl;
	file << "	return (*this);" << std::endl;
	file << "}" << std::endl;
	file << std::endl;
	file << "std::ostream & operator<<(std::ostream & o, " << nameFirstUpper << " const & i)" << std::endl;
	file << "{" << std::endl;
	file << "	o << \"Don't forget to change this.\";" << std::endl;
	file << "	return (o);" << std::endl;
	file << "}" << std::endl;
	file.close();
}

void	createHeader(std::string nameUpper, std::string nameFirstUpper)
{
	std::ofstream	file;
	std::string	fileName(nameFirstUpper + std::string(".hpp"));

	file.open(fileName.c_str());
	if (!file.is_open())
		return ;
	file << "#ifndef " << nameUpper << "_HPP" << std::endl;
	file << "# define " << nameUpper << "_HPP" << std::endl;
	file << std::endl;
	file << "#include <iostream>" << std::endl;
	file << std::endl;
	file << "class " << nameFirstUpper << std::endl;
	file << "{" << std::endl;
	file << "	public:" << std::endl;
	file << "		" << nameFirstUpper << "();" << std::endl;
	file << "		" << nameFirstUpper << "(" << nameFirstUpper << " const & src);" << std::endl;
	file << "		~" << nameFirstUpper << "();" << std::endl;
	file << std::endl;
	file << "		" << nameFirstUpper << " & operator=(" << nameFirstUpper << " const & rhs);" << std::endl;
	file << std::endl;
	file << "	private:" << std::endl;
	file << std::endl;
	file << "};" << std::endl;
	file << std::endl;
	file << "std::ostream & operator<<(std::ostream & o, " << nameFirstUpper << " const & i);" << std::endl;
	file << std::endl;
	file << "#endif /* !" << nameUpper << "_HPP" << " */" << std::endl;
	file.close();
}

int	main()
{
	std::string	line;
	std::string	nameUpper;
	std::string	nameFirstUpper;
	while (42)
	{
		std::cout << "Enter filename (without extension), or exit: ";
		std::getline(std::cin, line);
		if (line.compare("exit") == 0)
		{
			std::cout << "Bye. Bye :)" << std::endl;
			break ;
		}
		std::cout << "file name [" << line << "]" << std::endl;
		createNames(line, nameUpper, nameFirstUpper);
		createHeader(nameUpper, nameFirstUpper);
		createCpp(nameFirstUpper);
		std::cout << ".cpp & .hpp created" << std::endl;
		nameUpper.clear();
		nameFirstUpper.clear();
		line.clear();
	}
	return (0);
}
