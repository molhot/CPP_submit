/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:41:16 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/05/28 00:49:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int	main(void)
{
	FixNumber a;
	FixNumber b(a);
	FixNumber c;

	c = b;
	std::cout << a.get_value() << std::endl;
	std::cout << b.get_value() << std::endl;
	std::cout << c.get_value() << std::endl;

	a.set_value(10);

	std::cout << a.get_value() << std::endl;
	
	return 0;
}