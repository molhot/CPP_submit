/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 00:22:38 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/04/26 00:26:00 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char *argv[])
{
    int arg_position;
    int argv_position;

    if (argc == 1)
	{
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
    arg_position = 1;
    argv_position = 0;
    while (arg_position != argc)
    {
        while (argv[arg_position][argv_position] != '\0')
        {
            std::cout << (char)toupper(argv[arg_position][argv_position]);
            argv_position++;
        }
        arg_position++;
		if (argv[arg_position] != NULL)
			std::cout << " ";
        argv_position = 0;
    }
    std::cout << std::endl;
}