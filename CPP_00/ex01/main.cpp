/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:39:34 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 00:55:48 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <limits>
#include <iostream>
#include <stdbool.h>

void    output(std::string name)
{
    std::cout << name << std::endl;
}

bool    strcmp_cpp(std::string s1, std::string s2)
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

int main(void)
{
    Phonebook   book;
    size_t		i;
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
			std::cout << "input number 1 to 9 which you want to show info" << std::endl;
			std::cin >> index;
            book.showcontact(index);
			std::cout << std::endl;
		}
        else if (strcmp_cpp(operate, "EXIT"))
		{
			std::cout << "BUY!!:x" << std::endl;
            break ;
		}
        else
        {
            std::cout << std::endl;
            book.Manual();
        }
    }
    return (0);
}