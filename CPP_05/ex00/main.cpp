/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:40:12 by user              #+#    #+#             */
/*   Updated: 2023/06/15 18:49:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    //temp check//
    Bureaucrat b("jaeskim", 11);
	std::cout << b << std::endl;
	std::cout << std::endl;
	std::cout << "///////// increase test \\\\\\\\\\\\\\\\" << std::endl;
    std::cout << std::endl;
    try
    {
        b.increaseGrade(9);//2
        std::cout << b << std::endl;
        b.increaseGrade(1);//1
        std::cout << b << std::endl;
        b.increaseGrade(1);//over 1
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << "///////// decrease test \\\\\\\\\\\\\\\\" << std::endl;
	std::cout << std::endl;

    try
    {
        b.decreaseGrade(140);//141
        std::cout << b << std::endl;
        b.decreaseGrade(10);//over 150
        std::cout << b << std::endl;
        b.decreaseGrade(9);//150
        std::cout << b << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}