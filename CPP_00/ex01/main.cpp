/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:39:34 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/06/04 12:53:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <limits>
#include <iostream>
#include <string>
#include <vector>

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
	if (position == 0)
		return (false);
	return (true);
}

bool	operator_exec(std::string operate, Phonebook *book, int *i, bool *fillornot)
{
	std::string	index_str;
	int			index;

	if (operate == "ADD")
	{
		if (book->addcontact(*i) == false)
			std::cout << "add contact missed" << std::endl;
		else
		{
			std::cout << *i + 1 << "contact filled" << std::endl;
			*i = *i + 1;
		}
		if (*i == 8)
		{
			std::cout << "contact is maxed" << std::endl;
			*i = 0;
			*fillornot = true;
		}
	}
	else if (operate == "SEARCH")
	{
		std::cout << "input number 1 to 8 which you want to show info" << std::endl;
		std::getline(std::cin, index_str);
		std::cin.clear();
		try
		{
			index = std::stoi(index_str);
			if (index < 1 || 8 < index)
				std::cout << "input number 1 to 8" << std::endl;
			else if (*fillornot == true)
				book->showcontact(index);
			else if (index > *i)
				std::cout << "this is not filled..." << std::endl;
			else
				book->showcontact(index);
		}
		catch(...)
		{
			std::cout << "input int handling number" << std::endl;
		}
	}
	else if (operate == "EXIT")
	{
		std::cout << "BUY!!:x" << std::endl;
		return (false);
	}
	return (true);
}

bool	operater_ornot(std::string operater)
{
	if (operater == "ADD")
		return (true);
	else if (operater == "SEARCH")
		return (true);
	else if (operater == "EXIT")
		return (true);
	return (false);
}

int main(void)
{
	Phonebook	book;
	int			i;
	std::string operate;
	bool		contact_filled;
 
	book.Manual();
	i = 0;
	contact_filled = false;
	while (true)
	{
		operate = "";
		std::cout << "put your operate\n";
		std::cout.flush();
		std::getline(std::cin, operate);
		if (std::cin.eof() == true)
		{
			std::cin.clear();
			std::cout << "this is EOF!!" << std::endl;
			exit(1);
		}
		std::cin.clear();
		if (operater_ornot(operate) == true)
		{
			if (operator_exec(operate, &book, &i, &contact_filled) == false)
				break;
		}
		else
		{
			std::cout << "input is [ADD] or [SEARCH] or [EXIT]" << std::endl;
			std::cout.flush();
		}
	}
	return (0);
}