#ifndef CAT_HPP
# define CAT_HPP

# include <string>

class Cat
{
	public:
		Cat();
		~Cat();
		bool	readEntry(int ac, char **av);
		void	readEachLine(std::string fileName);
};

#endif /* !CAT_HPP */
