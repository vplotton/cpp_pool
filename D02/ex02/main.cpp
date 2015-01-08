/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:18:02 by mdufaud           #+#    #+#             */
/*   Updated: 2015/01/07 22:25:47 by vplotton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include "Fixed.hpp"

void	test(Fixed c, Fixed b)
{
	bool		test;

	std::cout << std::endl;
	std::cout << "* Testing compare *" << std::endl;
	std::cout << std::endl;
	test = c < b;
	std::cout << c << " < " << b << " operation: " << (test ? "true" : "false") << std::endl;
	test = c > b;
	std::cout << c << " > " << b << " operation: " << (test ? "true" : "false") << std::endl;
	test = c <= b;
	std::cout << c << " <= " << b << " operation: " << (test ? "true" : "false") << std::endl;
	test = c >= b;
	std::cout << c << " >= " << b << " operation: " << (test ? "true" : "false") << std::endl;
	test = c == b;
	std::cout << c << " == " << b << " operation: " << (test ? "true" : "false") << std::endl;
	test = c != b;
	std::cout << c << " != " << b << " operation: " << (test ? "true" : "false") << std::endl;
}

int main( void ) {
	Fixed 		a;
	Fixed const	b(Fixed( 5.05f ) * Fixed( 2 ));
	Fixed		c((Fixed( 1.03f) + (Fixed(30) - Fixed(7.2f)))/ Fixed(2));
	Fixed		add(Fixed(2) + Fixed(3));
	Fixed		sub(Fixed(3.2f) - Fixed(3.2f));
	Fixed		mult(Fixed(3.2f) * Fixed(3.2f));
	Fixed		div(Fixed(3.2f) / Fixed(3.2f));
	Fixed		y(c);
	Fixed		z;

	Fixed 		nb1(-6);
	Fixed 		nb2(6.05f);
	std::cout << nb1 << " - " << nb2 << " = " << (nb1 - nb2) << std::endl;
	z = y;
	test(c, b);
	std::cout << std::endl;
	std::cout << "* Testing operations on Fixed*" << std::endl;
	std::cout << std::endl;
	std::cout << "c(11.918): " << c << std::endl;
	std::cout << "add(5): " << add << std::endl;
	std::cout << "sub(0): " << sub << std::endl;
	std::cout << "mult(10.2344): " << mult << std::endl;
	std::cout << "div(1): " << div << std::endl;
	std::cout << "y(c): " << y << std::endl;
	std::cout << "z = w: " << z << std::endl;
	std::cout << std::endl;
	std::cout << "* Testing increment decrement, min/max*" << std::endl;
	std::cout << std::endl;
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
	std::cout << std::endl;
	std::cout << "* Testing logics *" << std::endl;
	std::cout << std::endl;
	std::cout << "a (0): " << a << std::endl;
	std::cout << "b (10.1016): " << b << std::endl;
	std::cout << "a + b: " << a + b << std::endl;
	std::cout << "a should be 0: " << a << std::endl;
	std::cout << "b should still be same b: " << b << std::endl;
	return 0;
}
