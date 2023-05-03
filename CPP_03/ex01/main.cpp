/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 22:17:51 by user              #+#    #+#             */
/*   Updated: 2023/05/04 05:32:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main()
{
    ClapTrap test_clap1("crap1");
    ScavTrap test_scav1("scav1");

    //test originalfunc
    test_scav1.GuardGate();
    //test_clap1.GuardGate(); this must not work because clapbox does not have this funcl
}