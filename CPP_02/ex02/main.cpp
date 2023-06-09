/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:41:16 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/09 22:39:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main( void ) {
	Fixed a;
	Fixed const b( 2147483646 ); 
	Fixed const c( 42.42f ); 
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	std::cout << "boolean test " << (a>b) << std::endl;
	if (a > b == 1)
		std::cout << "this is true" << std::endl;
	else
		std::cout << "this is false" << std::endl;
	std::cout << "a+a test " << (a+a) << std::endl;
	
	Fixed e;
	Fixed const f( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << e << std::endl;
	std::cout << ++e << std::endl;
	std::cout << e << std::endl;
	std::cout << e++ << std::endl;
	std::cout << e << std::endl;
	std::cout << f << std::endl;

	std::cout << Fixed::max( e, f ) << std::endl;
	
	return 0;
}