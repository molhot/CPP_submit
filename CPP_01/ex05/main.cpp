/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:24:11 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/05/28 00:23:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
	std::string	level;
	Harl		harl;

	level = "";
	while (level != "exit")
	{
		std::cout << "input level" << std::endl;
		std::getline(std::cin, level);
		harl.complain(level);
		std::cin.clear();
	}
}