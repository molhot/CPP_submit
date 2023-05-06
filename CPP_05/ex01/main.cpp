/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 22:40:12 by user              #+#    #+#             */
/*   Updated: 2023/05/06 14:48:30 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Breaucrat.hpp"
#include "Form.hpp"

int main()
{
    Breaucrat b("jaeskim", 1000);
	std::cout << b << std::endl;
	std::cout << std::endl;

	std::cout << "increase test" << std::endl;
	std::cout << std::endl;
    try
    {
        b.increaseGrade(9);
        std::cout << b << std::endl;
        b.increaseGrade(1);
        std::cout << b << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl;
	std::cout << "decrease test" << std::endl;
	std::cout << std::endl;

    try
    {
        b.decreaseGrade(140);
        std::cout << b << std::endl;
        b.decreaseGrade(10);
        std::cout << b << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}