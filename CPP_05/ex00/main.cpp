/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:40:12 by user              #+#    #+#             */
/*   Updated: 2023/06/17 16:59:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    //temp check//
    Bureaucrat b("jaesnlsjdlojadkim", 11);
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

    std::cout << std::endl;
    std::cout << "///////// incorrect implement test \\\\\\\\\\\\\\\\" << std::endl;
    std::cout << std::endl;

    //over 150 implement
    try
    {
        Bureaucrat missed("jaesnlsjdlojadkim", 152);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    //missed.decreaseGrade(); // this is not available because missed implement

    //over 1 implement
    try
    {
        Bureaucrat missed("jaesnlsjdlojadkim", 0);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << std::endl;

    return 0;
}