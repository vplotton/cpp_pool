/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vplotton <vplotton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/06 23:17:40 by vplotton          #+#    #+#             */
/*   Updated: 2015/01/06 23:40:14 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <fstream>
#include <iostream>
#include <cerrno>
#include <cstring>
#include <limits>

Cat::Cat()
{
}

Cat::~Cat()
{
}

void	Cat::readEachLine(std::string fileName)
{
	std::string		line;
	std::ifstream	input;

	if (fileName.empty())
	{
		while (std::getline(std::cin, line))
		{
			std::cout << line << std::endl;
		}
	}
	else
	{
		input.open(fileName.c_str());
		if (!input.is_open())
		{
			std::cout << "cat: " << fileName << ": "
				<< std::strerror(errno) << std::endl;
			return ;
		}
		while (std::getline(input, line))
		{
			std::cout << line << std::endl;
		}
	}
}

bool	Cat::readEntry(int ac, char **av)
{
	if (ac == 1)
	{
		readEachLine("");
	}
	else if (ac > 1)
	{
		for (int i = 1; i < ac; ++i)
		{
			readEachLine(av[i]);
		}
	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), EOF);
	return (true);
}

