/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:18:02 by mdufaud           #+#    #+#             */
/*   Updated: 2015/01/07 20:20:13 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Fixed.hpp"

void	test(Fixed a, Fixed b)
{
	bool		test;

	test = a < b;
	std::cout << a << " < " << b << " operation: " << test << std::endl;
	test = a > b;
	std::cout << a << " > " << b << " operation: " << test << std::endl;
	test = a <= b;
	std::cout << a << " <= " << b << " operation: " << test << std::endl;
	test = a >= b;
	std::cout << a << " >= " << b << " operation: " << test << std::endl;
	test = a == b;
	std::cout << a << " == " << b << " operation: " << test << std::endl;
	test = a != b;
	std::cout << a << " != " << b << " operation: " << test << std::endl;
}

int main( void )
{
	Fixed 		a;
	Fixed		c((Fixed( 1.03f) + (Fixed(30) - Fixed(7.2f)))/ Fixed(2));
	Fixed const	b(Fixed( 5.05f ) * Fixed( 2 ));

	Fixed		add(Fixed(1.03f) + Fixed(0.2f));
	Fixed		sub(Fixed(1.03f) - Fixed(0.2f));
	Fixed		mul(Fixed(1.03f) * Fixed(0.2f));
	Fixed		div(Fixed(1.03f) / Fixed(0.2f));

	std::cout << "add: " << add << std::endl;
	std::cout << "sub: " << sub << std::endl;
	std::cout << "mul: " << mul << std::endl;
	std::cout << "div: " << div << std::endl;

	test(c, b);
	std::cout << "a: " << a << std::endl;
	std::cout << "++a: " << ++a << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "a++: " << a++ << std::endl;
	std::cout << "a: "<< a << std::endl;
	std::cout << "const max(a, b): " << Fixed::max(a, b) << std::endl;
	std::cout << "const min(a, b): " << Fixed::min(a, b) << std::endl;
	std::cout << "max(a, c): " << Fixed::max(a, c) << std::endl;
	std::cout << "min(a, c): " << Fixed::min(a, c) << std::endl;
	std::cout << "--a: " << --a << std::endl;
	std::cout << "a--: " << a-- << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << b << std::endl;
	return (0);
}
