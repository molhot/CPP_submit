/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:58:45 by user              #+#    #+#             */
/*   Updated: 2023/05/11 07:30:10 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define SIZE 1000
#define SIZE2 42949672

int main()
{
	// int*			tmp_arr;
	// Array<int>		tmp(SIZE);
	// size_t			pos;
	// int				val;

	// pos = 0;
	// tmp_arr = new int[SIZE];
	// std::srand(std::time(NULL));
	// while (pos != SIZE)
	// {
	// 	val = std::rand();
	// 	//show 0 num
	// 	if (pos == 0)
	// 		std::cout << "[0] num is " << val << std::endl;
	// 	if (pos == 50)
	// 		std::cout << "[50] num is " << val << std::endl;
	// 	tmp_arr[pos] = val;
	// 	tmp[pos] = val;
	// 	pos++;
	// }
	// //catch the num in size
	// std::cout << std::endl;
	// std::cout << "correctsize check check" << std::endl;
	// std::cout << std::endl;
	// std::cout << "[0] num is " << tmp[0] << std::endl;
	// std::cout << "[50] num is " << tmp[50] << std::endl;
	// std::cout << std::endl;

	// //over size check
	// std::cout << "oversize check" << std::endl;
	// std::cout << std::endl;
	// try
	// {
	// 	std::cout << tmp[1000] << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;
	
	// //minus num
	// std::cout << "minusnum check" << std::endl;
	// std::cout << std::endl;
	// try
	// {
	// 	std::cout << tmp[-1] << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	// std::cout << std::endl;

	// //changetest
	// //in correct num
	// std::cout << "correctsize insert check" << std::endl;
	// std::cout << std::endl;
	// std::cout << "original [50] is " << tmp[50] << std::endl;
	// tmp[50] = 50;
	// std::cout << "next [50] is " << tmp[50] << std::endl;
	// std::cout << std::endl;

	int*			tmp_arr;
	Array<int>		tmp(SIZE2);
	size_t			pos;
	int				val;

	pos = 0;
	tmp_arr = new int[SIZE2];
	std::srand(std::time(NULL));
	try
	{
		while (pos != SIZE2)
		{
			val = std::rand();
			//show 0 num
			if (pos == 0)
				std::cout << "[0] num is " << val << std::endl;
			if (pos == 50)
				std::cout << "[50] num is " << val << std::endl;
			tmp_arr[pos] = val;
			tmp[pos] = val;
			pos++;
			if (pos % 1000 == 0)
				std::cout << "pos is " << pos << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "pos is " << pos << std::endl;
		std::cerr << e.what() << '\n';
	}
	//catch the num in size
	std::cout << std::endl;
	std::cout << "correctsize check check" << std::endl;
	std::cout << std::endl;
	std::cout << "[0] num is " << tmp[0] << std::endl;
	std::cout << "[50] num is " << tmp[50] << std::endl;
	std::cout << std::endl;

	//over size check
	std::cout << "oversize check" << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << tmp[SIZE2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	
	//minus num
	std::cout << "minusnum check" << std::endl;
	std::cout << std::endl;
	try
	{
		std::cout << tmp[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;

	//changetest
	//in correct num
	std::cout << "correctsize insert check" << std::endl;
	std::cout << std::endl;
	std::cout << "original [50] is " << tmp[50] << std::endl;
	tmp[50] = 50;
	std::cout << "next [50] is " << tmp[50] << std::endl;
	std::cout << std::endl;

	std::cout << "oversize check" << std::endl;
	std::cout << std::endl;
	try
	{
		tmp[SIZE2] = 100;
		std::cout << tmp[SIZE2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
	
	//minus num
	std::cout << "minusnum check" << std::endl;
	std::cout << std::endl;
	try
	{
		tmp[-1] = 100;
		std::cout << tmp[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << std::endl;
}