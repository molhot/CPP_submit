/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 05:00:43 by user              #+#    #+#             */
/*   Updated: 2023/05/04 05:33:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name):ClapTrap(name)
{
    std::cout << "Scav Trap constructor called" << std::endl;
    this->_hp = 100;
    this->_ep = 50;
    this->_a = 20;
}

ScavTrap::~ScavTrap()
{
    std::cout << "Scav Trap denstructor called" << std::endl;
}

void    ScavTrap::GuardGate()
{
    std::cout << "guard gate is called!" << std::endl;
}
