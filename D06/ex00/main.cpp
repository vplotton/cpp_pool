/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbres <sbres@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 16:22:31 by sbres             #+#    #+#             */
/*   Updated: 2015/01/13 16:22:53 by sbres            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdlib.h>
#include "Scalar.hpp"

int main(int argc, char const *argv[])
{
	/* code */
	double test;
	char * toto;

	if (argc == 1)
	{
		std::cout << "Please specify parameter" << std::endl;
		return 0;
	}
	test = strtod(argv[1], &toto);
	if (test == 0 && toto == argv[1])
	{
		Scalar value1 = Scalar(argv[1][0]);
		std::cout << value1 <<std::endl;
	}
	else
	{
		Scalar value1 = Scalar(test);
		std::cout << value1 <<std::endl;
	}
	return 0;
}

