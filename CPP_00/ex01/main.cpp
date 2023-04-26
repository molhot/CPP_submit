/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:39:34 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 18:03:16 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <limits>
#include <iostream>
#include <stdbool.h>

bool	strcmp_cpp(std::string s1, std::string s2)
{
	size_t  position;

	position = 0;
	while (s1[position] != '\0')
	{
		if (s1[position] != s2[position])
			return (false);
		position++;
	}
	if (s2[position] != '\0')
		return (false);
	return (true);
}

bool	ft_isdigit(std::string sub)
{
	size_t  pos;

	pos = 0;
	while (sub[pos] != '\0')
	{
		if ('0' <= sub[pos] && sub[pos] <= '9')
			pos++;
		else
			return (false);
	}
	return (true);
}

int main(void)
{
	Phonebook	book;
	size_t		i;
	std::string	index_str;
	int			index;
	std::string name;
	std::string operate;
	
	i = 0;
	book.Manual();
	while (true)
	{
		std::cout << "put your operate" << std::endl;
		std::cin >> operate;
		std::cout << std::endl;
		if (strcmp_cpp(operate, "ADD"))
		{
			book.addcontact(i);
			std::cout << std::endl;
			i++;
		}
		else if (strcmp_cpp(operate, "SEARCH"))
		{
			std::cout << "input number 1 to 8 which you want to show info" << std::endl;
			std::cin >> index_str;
			if (ft_isdigit(index_str) == false) 
				std::cout << "enter number" << std::endl;
			else
			{
				try
				{
					index = std::stoi(index_str);
					if (index < 1 || 8 < index)
						std::cout << "input number 1 to 8" << std::endl;
					else if (index > i)
						std::cout << "this is not filled..." << std::endl;
					else
						book.showcontact(index);
				}
				catch(...)
				{
					std::cout << "input unser int max" << std::endl;
				}
			}
		}
		else if (strcmp_cpp(operate, "EXIT"))
		{
			std::cout << "BUY!!:x" << std::endl;
			break ;
		}
		book.Manual();
	}
	return (0);
}