/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:17:51 by user              #+#    #+#             */
/*   Updated: 2023/06/11 13:29:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    ClapTrap test_clap1("crap1");
    test_clap1.attack("aa");

    ScavTrap test_scav1("scav1");
    FragTrap test_frag1("frag1");


    //test originalfunc
    std::cout << std::endl;
    test_scav1.guardGate();
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