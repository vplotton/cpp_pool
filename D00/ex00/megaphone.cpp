#include <iostream>

int		main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
	else if (ac > 1)
	{
		for (int j = 1 ; j < ac ; ++j)
		{
			i = 0;
			while (av[j][i])
			{
				std::cout << (char)std::toupper(av[j][i]);
				++i;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
