/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:14:38 by user              #+#    #+#             */
/*   Updated: 2023/05/10 00:37:48 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	show_vector(Span const &sub)
{
	size_t				pos;
	size_t				array_size;
	std::vector<int>	array;

	pos = 0;
	array = sub.get_array();
	array_size = sub.get_array().size();
	while (pos != array_size)
	{
		std::cout << array[pos] << " ";
		pos++;
	}
	std::cout << std::endl;
}

int main()
{
	Span	nanka(10);

	try
	{
		nanka.addNumbers_random(10);
	}
	catch(const std::exception& e)
	{
		std::cout << "Input num is error" << std::endl;
		exit(1);
	}
	show_vector(nanka);
	std::cout << nanka.shortestSpan() << std::endl;
	std::cout << nanka.longestSpan() << std::endl;
}