/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 19:48:39 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 19:56:07 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main()
{
	std::string	str;
	std::string	*stringPTR;
	std::string	&stringREF = str;

	str = "HI THIS IS BRAIN";
	stringPTR = &str;
	// stringREF = str;
	std::cout << &str << " && " << str << std::endl;
	std::cout << stringPTR << " && " << *stringPTR << std::endl;
	std::cout << &stringREF << " && " << stringREF << std::endl;

	std::string	test;

	test = "test";
	stringPTR = &test;
	stringREF = test;
	std::cout << &test << " && " << test << std::endl;
	std::cout << stringPTR << " && " << *stringPTR << std::endl;
	std::cout << &stringREF << " && " << stringREF << std::endl;
}