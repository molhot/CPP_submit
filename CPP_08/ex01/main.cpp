/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 23:14:38 by user              #+#    #+#             */
/*   Updated: 2023/07/01 18:08:48 by user             ###   ########.fr       */
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

void	copy_const_and_copy_assignment_test()
{
	Span	some(3);

	some.addNumbers_random(3);
	show_vector(some);
	try
	{
		some.addNumber(0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "===========" << std::endl;
	Span	some2(some);
	Span	some3;
	some3 = some;

	std::cout << "==============" << std::endl;
	std::cout << "some's test" << std::endl;
	std::cout << "some sortest span is " << some.shortestSpan() << std::endl;
	std::cout << "some logest span is " << some.longestSpan() << std::endl;
	std::cout << "==============" << std::endl;
	std::cout << std::endl;
	std::cout << "some2's test" << std::endl;
	std::cout << "some2 sortest span is " << some2.shortestSpan() << std::endl;
	std::cout << "some2 logest span is " << some2.longestSpan() << std::endl;
	std::cout << "==============" << std::endl;
	std::cout << std::endl;
	std::cout << "some3's test" << std::endl;
	std::cout << "some3 sortest span is " << some3.shortestSpan() << std::endl;
	std::cout << "some3 logest span is " << some3.longestSpan() << std::endl;
	std::cout << "==============" << std::endl;
	std::cout << std::endl;
}

#define SIZE 10

int main()
{
	//std::cout << static_cast<unsigned int>(INT_MAX + INT_MAX + 1) << std::endl;
	std::cout << static_cast<unsigned int>(INT_MAX) << std::endl;
	std::cout << static_cast<unsigned int>(INT_MIN) << std::endl;
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

	copy_const_and_copy_assignment_test();

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
	system("leaks -q ex01");
}