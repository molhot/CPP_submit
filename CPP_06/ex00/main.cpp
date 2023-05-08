/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 23:40:05 by user              #+#    #+#             */
/*   Updated: 2023/05/08 11:44:13 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "You must write argment" << std::endl;
		std::cout << "like ./ex00 a" << std::endl;
		exit(1);
	}
	Convert sub(argv[1]);
	std::cout << sub << std::endl;
}