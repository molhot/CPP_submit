/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 20:35:14 by user              #+#    #+#             */
/*   Updated: 2023/06/21 15:43:53 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	int a = 2;
	int b = 3;

	swap(a, b);
	std::cout << "a is " << a << " and b is " << b << std::endl;
	std::cout << "min test is " << min(a, b) << std::endl;

	//writingtest
	::swap(a, b);//こんな書き方もあるらしい
	std::cout << "a is " << a << " and b is " << b << std::endl;

	//change type
	std::string nanka = "nanka";
	std::string nanka_big = "NANKA";
	swap(nanka, nanka_big);
	std::cout << "nanka is " << nanka << " and NANKA is " << nanka_big << std::endl;
	std::cout << "max test is " << min(nanka, nanka_big) << std::endl;

	//this can not handled
	//swap(a, nanka);
}