/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:24:11 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/07 23:19:31 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	std::string	level;
	Harl		harl;

	level = "";
	std::cout << "input [DEBUG, INFO, WARNING, ERROR]" << std::endl;
	while (true)
	{
		std::cout << "input level" << std::endl;
		std::getline(std::cin, level);
		harl.complain(level);
		std::cin.clear();
	}
}