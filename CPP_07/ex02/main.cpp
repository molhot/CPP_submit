/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 21:58:45 by user              #+#    #+#             */
/*   Updated: 2023/06/21 17:36:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define SIZE2 1000

void	test_correctarray(Array<int>& some)
{
	std::cout << "==== get correctly array num =========" << std::endl;
	std::cout << "100 > " << some[100] << " & 300 > " << some[300] << std::endl;
	std::cout << "======================================" << std::endl;
	//* after, i try incorrect array num
}

int main()
{
	Array<int>		tmp(SIZE2);
	size_t			pos;

	pos = 0;
	std::srand(std::time(NULL));
	while (pos != SIZE2)
	{
		tmp[pos] = std::rand();
		pos++;
	}
	//catch the num in size
	test_correctarray(tmp);
	std::cout << std::endl;

	//over size check
	std::cout << "=========== overarray check ==============" << std::endl;
	try
	{
		std::cout << tmp[SIZE2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "======================================" << std::endl;
	std::cout << std::endl;
	
	//minus num
	std::cout << "=========== minusnum check ==============" << std::endl;
	try
	{
		std::cout << tmp[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "======================================" << std::endl;
	std::cout << std::endl;

	//changetest
	//in correct num
	std::cout << "=========== correctsize insert check ===============" << std::endl;
	std::cout << "original [50] is " << tmp[50] << std::endl;
	tmp[50] = 50;
	std::cout << "next [50] is " << tmp[50] << std::endl;
	std::cout << "======================================" << std::endl;
	std::cout << std::endl;

	std::cout << "=========== oversize check ===============" << std::endl;
	try
	{
		tmp[SIZE2] = 100;
		std::cout << tmp[SIZE2] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "======================================" << std::endl;
	std::cout << std::endl;
	
	//minus num
	std::cout << "========= minusnum change check =============" << std::endl;
	try
	{
		tmp[-1] = 100;
		std::cout << tmp[-1] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "======================================" << std::endl;
	std::cout << std::endl;

	std::cout << "========= copy constructor check =============" << std::endl;
	Array<int>		tmp2(tmp);

	std::cout << "tmp[50] > " << tmp[50] << " | tmp2[50] > " << tmp2[50] << std::endl;
	std::cout << "~~ change num ~~" << std::endl;
	tmp2[50] = 1;
	std::cout << "tmp[50] > " << tmp[50] << " | tmp2[50] > " << tmp2[50] << std::endl;
	std::cout << "checking above result !" << std::endl;
	std::cout << std::endl;

	std::cout << "========= copy assignment check =============" << std::endl;
	Array<int>		tmp3(SIZE2);
	tmp3 = tmp;
	std::cout << "tmp[50] > " << tmp[50] << " | tmp3[50] > " << tmp3[50] << std::endl;
	std::cout << "tmp[200] > " << tmp[200] << " | tmp3[200] > " << tmp3[200] << std::endl;
	tmp3[50] = 1;
	std::cout << "~~ change num ~~" << std::endl;
	std::cout << "tmp[50] > " << tmp[50] << " | tmp3[50] > " << tmp3[50] << std::endl;
	std::cout << "checking above result !" << std::endl;
	std::cout << std::endl;
	

	system("leaks -q ex02");
	std::cout << std::endl;
}