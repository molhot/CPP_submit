/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 20:00:52 by user              #+#    #+#             */
/*   Updated: 2023/06/24 03:06:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.hpp"

int main()
{
	Base *some = generate();
	identify(some);
	identify(*some);

	delete(some);
	
	some = NULL;
	std::cout << std::endl;
	std::cout << "NULL check" << std::endl;
	std::cout << std::endl;
	identify(some);

	system("leaks -q ex02");
	//identify(*some);参照私なのでNULLha許容されない
}