/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 19:28:16 by user              #+#    #+#             */
/*   Updated: 2023/05/08 20:06:09 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.h"

uintptr_t	serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	Data *test = new Data;

	test->_nanka = "nanka";
	std::cout << "nanka address is " << test << std::endl;
	std::cout << "nanka nbr is " << serialize(test) << std::endl;
	if ((long long)test == serialize(test))
		std::cout << "correctly there is same nbr" << std::endl;
	std::cout << "nanka is " << deserialize(serialize(test))->_nanka << std::endl;

	test = NULL;
	std::cout << "nanka address is " << test << std::endl;
	std::cout << "nanka nbr is " << serialize(test) << std::endl;
	if ((long long)test == serialize(test))
		std::cout << "correctly there is same nbr" << std::endl;
	if (test != NULL)
		std::cout << "nanka is " << deserialize(serialize(test))->_nanka << std::endl;

	delete test;
}