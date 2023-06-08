/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:17:51 by user              #+#    #+#             */
/*   Updated: 2023/06/08 22:12:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap test_clap1("crap1");
    ScavTrap test_scav1("scav1");
    ScavTrap test2 = test_scav1;
    ScavTrap test3("test3");

    //test originalfunc
    test_scav1.GuardGate();
    //test_clap1.GuardGate(); //this must not work because clapbox does not have this funcl
    test2.GuardGate();
    test3.GuardGate();
    test3 = test2;
    
    test_clap1.attack("nanka");
    std::cout << std::endl;
    test3.attack("nanka");

    ClapTrap *nanka = &test_scav1;
    ScavTrap *nanka2 = &test_scav1;

    nanka->attack("nnn");
    nanka2->attack("nnn");
}