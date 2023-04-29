/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:17:51 by user              #+#    #+#             */
/*   Updated: 2023/04/29 23:35:06 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main()
{
    ClapTrap test1("TEST1");
    ClapTrap test2("TEST2");

    std::cout << "test temporary function" << std::endl;
    test1.attack("TEST2");
    test1.be_Repaired(10);
    test1.takeDamage(10);
    std::cout << std::endl;
    std::cout << "test over hp damaged" << std::endl;
    test1.takeDamage(9999);
    std::cout << std::endl;
    std::cout << "test when hp is 0" << std::endl;
    test1.takeDamage(9999);
    std::cout << std::endl;
    std::cout << "test when ep is 0" << std::endl;
    size_t  i = 10;
    while (i != 0)
    {
        test2.be_Repaired(1);
        i--;
    }
    std::cout << "above, test case!" << std::endl;
    test2.be_Repaired(100);
}