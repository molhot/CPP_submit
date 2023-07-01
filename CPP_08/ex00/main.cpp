/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 22:08:00 by user              #+#    #+#             */
/*   Updated: 2023/07/01 16:53:23 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include "easyfind.tpp"

int main()
{
	std::string nanka;

	nanka = "PNNNAAAAANNNNNKKKKKKAAAAAA";
	if (easyfind(nanka, INT_MAX) == 1)
		std::cout << "error" << std::endl;
}