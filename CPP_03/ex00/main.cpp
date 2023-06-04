/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:17:51 by user              #+#    #+#             */
/*   Updated: 2023/06/04 17:21:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <stdio.h>
#include <stdlib.h>

void    testing(ClapTrap nanka)
{
    nanka.takeDamage(20);
    return ;
}

void    testing(ClapTrap *nanka)
{
    nanka->takeDamage(20);
    return ;
}

int main()
{
    ClapTrap test1("TEST1");
    ClapTrap test2("TEST2");
    ClapTrap test3("TEST3");

    std::cout << "test temporary function" << std::endl;
    std::cout << std::endl;
    test1.attack("TEST2");
    test1.be_Repaired(10);
    test1.takeDamage(10);
    std::cout << std::endl;
    std::cout << "test over hp damaged" << std::endl;
    std::cout << std::endl;
    test1.takeDamage(9999);
    std::cout << std::endl;
    std::cout << "test when hp is 0" << std::endl;
    std::cout << std::endl;
    test1.takeDamage(9999);
    std::cout << std::endl;
    std::cout << "test when ep is 0" << std::endl;
    std::cout << std::endl;
    size_t  i = 10;
    while (i != 0)
    {
        test2.be_Repaired(1);
        i--;
    }
    std::cout << "above, test case!" << std::endl;
    test2.be_Repaired(100);

    std::cout << "over function" << std::endl;
    std::cout << std::endl;
    testing(test3);
    test3.be_Repaired(20);
    std::cout << std::endl;

    std::cout << "address check" << std::endl;
    ClapTrap *test4 = new ClapTrap("TEST4");
    testing(test4);
    test4->be_Repaired(100);
    delete test4;
    std::cout << "~~~~~~" << std::endl;

    std::cout << std::endl;
}