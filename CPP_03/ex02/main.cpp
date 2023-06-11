/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:17:51 by user              #+#    #+#             */
/*   Updated: 2023/06/11 13:44:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

void    prevtest()
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
}

int main()
{
    prevtest();
    ClapTrap test_clap1("crap1");
    test_clap1.attack("aa");

    ScavTrap test_scav1("scav1");
    FragTrap test_frag1("frag1");


    //test originalfunc
    std::cout << std::endl;
    test_scav1.guardGate();
    // test_scav1.highFivesGuys(); can not access
    //test_clap1.GuardGate(); this must not work because clapbox does not have this funcl
    std::cout << std::endl;
    test_frag1.highFivesGuys();
    std::cout << std::endl;
    //attack test
    test_scav1.attack("enemy");
    std::cout << std::endl;
    test_frag1.attack("enemy");
    std::cout << std::endl;

    //
    std::cout << std::endl;
    ScavTrap test_scav2(test_scav1);
    //test_scav2 = test_scav1;
    test_scav2.guardGate();
    std::cout << std::endl;

    std::cout << std::endl;
    ScavTrap test_scav3("scav3");
    test_scav3 = test_scav1;
    test_scav3.attack("mochi");

    std::cout << std::endl;
    FragTrap test_frag2("frag2");
    test_frag2 = test_frag1;
    test_frag2.attack("mochi");
    test_frag2.highFivesGuys();

    // test_scav2.GuardGate();
    FragTrap nana(test_frag2);
    nana.highFivesGuys();

    std::cout << std::endl;
}