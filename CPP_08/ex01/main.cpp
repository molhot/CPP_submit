/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:14:38 by user              #+#    #+#             */
/*   Updated: 2023/06/21 21:15:30 by user             ###   ########.fr       */
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

void	subject_test()
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << "<< shortestSpan func check >>" << std::endl;
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << "<< lengestSpan func check >>" << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

#define SIZE 10

int main()
{
	std::cout << "====== subject check ======" << std::endl;
	subject_test();
	std::cout << "====== subject check end ======" << std::endl;
	std::cout << std::endl;
	
	Span	nanka(SIZE);
	try
	{
		nanka.addNumbers_random(SIZE);
	}
	catch(const std::exception& e)
	{
		std::cout << "Input num is error" << std::endl;
		exit(1);
	}
	show_vector(nanka);
	std::cout << "<< shortestSpan func check >>" << std::endl;
	std::cout << nanka.shortestSpan() << std::endl;
	std::cout << "<< lengestSpan func check >>" << std::endl;
	std::cout << nanka.longestSpan() << std::endl;

	//使う意味はないが。。。
	Span no_elem;
	
	try
	{
		no_elem.addNumber(10);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		no_elem.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		no_elem.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}