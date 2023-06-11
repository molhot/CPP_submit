/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:17:51 by user              #+#    #+#             */
/*   Updated: 2023/06/11 13:27:03 by user             ###   ########.fr       */
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
    test_scav1.guardGate();
    //test_clap1.GuardGate(); //this must not work because clapbox does not have this funcl
    test2.guardGate();
    test3.guardGate();
    test3 = test2;
    
    test_clap1.attack("nanka");
    std::cout << std::endl;
    test3.attack("nanka");

    ClapTrap *nanka = &test_scav1;
    ScavTrap *nanka2 = &test_scav1;

    nanka->attack("nnn");
    nanka2->attack("nnn");

    ScavTrap    hero;
    ScavTrap    enemy1("Kefka");
    ScavTrap    enemy2 = enemy1;
    ScavTrap    enemy3;

    enemy3 = enemy2;

    std::cout << "-------------------------\n";
    hero.attack("Kefka");
    hero.guardGate();
    hero.guardGate();
    hero.attack("Kefka");
    hero.beRepaired(100);
    std::cout << "-------------------------\n";
    std::cout << enemy2;
    std::cout << enemy3;
    std::cout << enemy1;
    std::cout << "-------------------------\n";
    enemy1.takeDamage(10);
    std::cout << enemy1;
    std::cout << "-------------------------\n";
    enemy1.beRepaired(100);
    std::cout << enemy1;
    std::cout << "-------------------------\n";
    enemy1.attack("Kefka");//enemy1 と　kefkaは同名なのでレビュワーさんにその旨伝えること
    std::cout << enemy1;
    std::cout << "-------------------------\n";
    enemy1.beRepaired(100);
    std::cout << enemy1;

    return 0;
}